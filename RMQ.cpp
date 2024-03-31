// Range Minimum Queries
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
#define max 1000000
const int LG = 19;
int a[max], st[LG+1][max];

void preprocess(int n){
    for(int i = 1; i <= n; ++i){
        st[0][i] = a[i];
    }
    for(int j = 1; j <= LG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            st[j][i] = min(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
    }
}

int queryMin(int l, int r){
    int k = __lg(r-l+1);
    return min(st[k][l], st[k][r-(1<<k)+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    preprocess(n);
    int q; cin >> q;
    long sum = 0;
    while(q--){
        int l, r;
        cin >> l >> r;
        sum += queryMin(l+1,r+1);
    }
    cout << sum << endl;
    return 0;
}
