#include<iostream>
#include<algorithm>

using namespace std;
int n, a[10000];

int MaxLeftMid(int i, int m){
    int ans = a[m], sum = 0;
    for(int k = m; k >= i; k--){
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int MaxRightMid(int m, int j){
    int ans = a[m], sum = 0;
    for(int k = m; k <= j; k++){
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
} 

int MaxSubSeq(int i, int j){
    if(i == j) return a[i];
    int m = (i+j)/2;
    
    int wL = MaxSubSeq(i, m);
    int wR = MaxSubSeq(m+1, j);
    
    int wLM = MaxLeftMid(i, m);
    int wRM = MaxRightMid(m+1, j);
    int wM = wLM + wRM;
    
    return max(max(wL, wR), wM);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << MaxSubSeq(0,n-1);
    return 0;
}