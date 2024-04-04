// Capacitated Vehicle Routing Problems
// 03/2024 - this solve chi accept 3/5 (TLE) 
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>

using namespace std;

int K, Q, n, f, fopt, nbR, segments, cmin;
int visited[12], x[12], y[12], load[5], c[13][13], d[12];

bool checkX(int v, int k){
    if(v > 0 && visited[v]) 
        return false;
    if(load[k] + d[v] > Q)
        return false;
    return true;
}

void Try_X(int s, int k){  // gan x[s] cho xe thu k
    if(s == 0){ // hanh trinh xe k ket thuc
        if(k < K) 
            Try_X(y[k+1], k+1);
        return;
    }
    for(int v = 0; v <= n; v++){
        if(checkX(v,k)){
            x[s] = v; visited[v] = true;
            f += c[s][v]; load[k] += d[v];
            segments = segments + 1;
            
            if(v > 0){
                int ftemp = f + (n + nbR - segments)*cmin;
                if(ftemp < fopt) Try_X(v,k);
            } else {
                if(k == K){
                    if((n + nbR) == segments){
                        // update best
                        if(f < fopt) fopt = f;
                    }
                } else{
                    int ftemp = f + (n + nbR - segments)*cmin;
                    if(ftemp < fopt) Try_X(y[k+1], k+1);
                }
            }
            // backtrack
            visited[v] = false;
            f -= c[s][v]; load[k] -= d[v];
            segments = segments - 1;
        }
    }
}

bool checkY(int v, int k){
    if(v == 0) return true;
    if(visited[v]) 
        return false;
    if(load[k] + d[v] > Q) 
        return false;
    return true;
}

void Try_Y(int k){
    int s = 0;
    if(y[k-1] > 0) s = y[k-1]+1;
    for(int v = s; v <= n; v++){
        if(checkY(v,k)){
            y[k] = v; 
            if(v > 0) segments = segments + 1;
            visited[v] = true; f += c[0][v]; load[k] += d[v];
            
            if(k < K) Try_Y(k+1);
            else {
                nbR = segments;
                Try_X(y[1],1);
            }
            // backtrack
            if(v > 0) segments = segments - 1;
            visited[v] = false; f -= c[0][v]; load[k] -= d[v];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    f = 0; fopt = INT_MAX;
    y[0] = 0; cmin = 10000; segments = 0;
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) visited[i] = false;
    memset(load, K, 0);        
    Try_Y(1);
    cout << fopt << endl;
}
