// bai toan nguoi di du lich

#include<bits/stdc++.h>

using namespace std;
const int N = 20;
const int INF = 1e9;
int n, C[N][N], mem[N][1<<N];

int TSP(int i, int S){
    if(S == (1 << N) - 1)
        return mem[i][S] = C[i][0];
    if(mem[i][S] != -1) return mem[i][S];
    int res =  INF;
    for(int j = 1; j <= N; j++){
        if(S & (1 << j)) continue;
        res = min(res, C[i][j] + TSP(j, S | (1 << j)));
    }
    return mem[i][S] = res;
}

int main(){
    // tu lam not di=))
}