// Bai toan cai tui (Knapsack Problem)

#include<bits/stdc++.h>

using namespace std;
int Value[10005][10005];
int w[10005], v[10005];
int n,L;

int Knap(){
    for(int k = 0; k <= n; k++){
        for(int S = 0; S < L; S++){
            if(k == 0 || S == 0) Value[k][S] = 0;
            else if(S < w[k])
                Value[k][S] = Value[k-1][S];
            else
                Value[k][S] = max(Value[k-1][S], v[k] + Value[k-1][S-w[k]]);
        }
    }
    return Value[n][L];
}

int main(){
    cin >> n >> L;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int j = 0; j < n; j++) cin >> w[j];

    cout << Knap() << endl;
    return 0;
}