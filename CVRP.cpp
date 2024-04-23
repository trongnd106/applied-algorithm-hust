// Capacitated Vehicle Routing Problems
// UPDATE 04/2024 - accept 5/5
#include <bits/stdc++.h>

using namespace std;

int c[15][15], s[7][15], d[15], vi[15] = {};
int n, kni, k, ki, q, mn = 1e6, p = 0, cmin = 1e6, c0min = 1e6;

int cal(){
    int dis = (n - p) * cmin, dii = 0;
    for(int i = 1; i <= n; ++i)
        if(!vi[i])
            dii += d[i];
    for(int i = 1; i <= k; ++i){
        int j = -1, ci = c[0][s[i][0]], di = 0;
        while(s[i][++j]){
            ci += c[s[i][j]][s[i][j+1]];
            di += d[s[i][j]];
        }
        if(i >= ki){
            ci += c0min - c[s[i][j-1]][0];
            dii += di % q;
        }
        dis += ci * ((di + q - 1) / q);
    }
    if(dii > q * (k + 1 - ki))
        dis += 2 * c0min + cmin;
    return dis;
}

void X(){
    if(p == n){
        int dis = 0;
        for(int i = 1; i <= k; ++i){ 
            int j = -1, ci = c[0][s[i][0]], di = 0;
            while(s[i][++j]){
                ci += c[s[i][j]][s[i][j+1]];
                di += d[s[i][j]];
            }
            dis += ci * ((di + q - 1) / q);
        }
        if(dis < mn)
            mn = dis;
        return;
    }
    if(ki < k){
        int tmp = kni;
        ++ki;
        kni = 1;
        X();
        --ki;
        kni = tmp;
    }
    for(int i = 1; i <= n; ++i)
        if(!vi[i]){
            s[ki][kni++] = i;
            ++p;
            vi[i] = 1;
            if(cal() < mn)
                X();
            vi[i] = 0;
            --p;
            s[ki][--kni] = 0;
        }
}

void Y(int a){
    if(a > k){
        p = k;
        ki = 1;
        kni = 1;
        X(); 
        return;
    }
    for(int i = s[a-1][0] + 1; i <= n; i++){
        s[a][0] = i;
        vi[i] = 1;
        Y(a + 1);
        vi[i] = 0;
    }
}

int main(){
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for(int i = 0; i <= n; i++){
        scanf("%d", &c[i][0]);
        if(c[i][0])
            c0min = min(c[i][0], c0min);
        for(int j = 1; j <= n; j++){
            scanf("%d", &c[i][j]);
            if(c[i][j])
                cmin = min(c[i][j], cmin);
        }
    }
    ++k;
    while(--k){
        Y(1);
    } 
    cout << mn;
}




// 03/2024 - this solve chi accept 3/5 (TLE) 
// #include<iostream>
// #include<algorithm>
// #include<climits>
// #include<cstring>

// using namespace std;

// int K, Q, n, f, fopt, nbR, segments, cmin;
// int visited[12], x[12], y[12], load[5], c[13][13], d[12];

// bool checkX(int v, int k){
//     if(v > 0 && visited[v]) 
//         return false;
//     if(load[k] + d[v] > Q)
//         return false;
//     return true;
// }

// void Try_X(int s, int k){  // gan x[s] cho xe thu k
//     if(s == 0){ // hanh trinh xe k ket thuc
//         if(k < K) 
//             Try_X(y[k+1], k+1);
//         return;
//     }
//     for(int v = 0; v <= n; v++){
//         if(checkX(v,k)){
//             x[s] = v; visited[v] = true;
//             f += c[s][v]; load[k] += d[v];
//             segments = segments + 1;
            
//             if(v > 0){
//                 int ftemp = f + (n + nbR - segments)*cmin;
//                 if(ftemp < fopt) Try_X(v,k);
//             } else {
//                 if(k == K){
//                     if((n + nbR) == segments){
//                         // update best
//                         if(f < fopt) fopt = f;
//                     }
//                 } else{
//                     int ftemp = f + (n + nbR - segments)*cmin;
//                     if(ftemp < fopt) Try_X(y[k+1], k+1);
//                 }
//             }
//             // backtrack
//             visited[v] = false;
//             f -= c[s][v]; load[k] -= d[v];
//             segments = segments - 1;
//         }
//     }
// }

// bool checkY(int v, int k){
//     if(v == 0) return true;
//     if(visited[v]) 
//         return false;
//     if(load[k] + d[v] > Q) 
//         return false;
//     return true;
// }

// void Try_Y(int k){
//     int s = 0;
//     if(y[k-1] > 0) s = y[k-1]+1;
//     for(int v = s; v <= n; v++){
//         if(checkY(v,k)){
//             y[k] = v; 
//             if(v > 0) segments = segments + 1;
//             visited[v] = true; f += c[0][v]; load[k] += d[v];
            
//             if(k < K) Try_Y(k+1);
//             else {
//                 nbR = segments;
//                 Try_X(y[1],1);
//             }
//             // backtrack
//             if(v > 0) segments = segments - 1;
//             visited[v] = false; f -= c[0][v]; load[k] -= d[v];
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     f = 0; fopt = INT_MAX;
//     y[0] = 0; cmin = 10000; segments = 0;
//     cin >> n >> K >> Q;
//     for(int i = 1; i <= n; i++) cin >> d[i];
//     for(int i = 0; i <= n; i++){
//         for(int j = 0; j <= n; j++){
//             cin >> c[i][j];
//             cmin = min(cmin, c[i][j]);
//         }
//     }
//     for(int i = 1; i <= n; i++) visited[i] = false;
//     memset(load, K, 0);        
//     Try_Y(1);
//     cout << fopt << endl;
// }
