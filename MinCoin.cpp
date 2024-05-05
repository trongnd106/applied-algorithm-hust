// Bai toan doi tien 

#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;
const int N = 20;
const int XMAX = 1e5 + 5;
int D[N], mem[N][XMAX];

int MinCoin(int i, int x){
    if(x <= 0 || i == 0) return INF;
    if(x == 0) return 0;
    if(mem[i][x] != -1) return mem[i][x];

    int res = INF;
    res = min(1 + MinCoin(i, x-D[i]), MinCoin(i-1,x));
    return mem[i][x] = res;
}

int main(){
    memset(mem, -1, sizeof(mem));
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> D[i];
    int x; cin >> x;

    cout << MinCoin(n,x) << endl;
    return 0;
}