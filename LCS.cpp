// Day con chung dai nhat
// Longest Common Subsequence - LCS

// option 1: Recursive 
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int X[10005], Y[10005], mem[10005][10005];
int n,m;

int lcs(int i, int j){
    if(i == 0 || j == 0) return 0;
    if(mem[i][j] != -1) return mem[i][j];
    int res;
    if(X[i] == Y[j]) 
        res = 1 + lcs(i-1,j-1);
    else 
        res = max(lcs(i,j-1), lcs(i-1,j));
    mem[i][j] = res;
    return res;
}

// truy vet phan tu
void trace(int i, int j){
    if(i == -1 || j == -1) return;
    if(mem[i][j] == mem[i-1][j]){
        trace(i-1,j);
        return;
    }
    if(mem[i][j] == mem[i][j-1]){
        trace(i,j-1);
        return;
    }
    if(X[i] == Y[j] && mem[i][j] == 1 + mem[i-1][j-1]){
        trace(i-1,j-1);
        cout << X[i] << " ";
        return;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> X[i];
    for(int j = 1; j <= m; j++) cin >> Y[j];

    memset(mem, -1, sizeof(mem));
    cout << lcs(n,m) << endl;
    return 0;
}





// option 2: For loop
/*
#include<bits/stdc++.h>

using namespace std;
int mem[1000][1000];
int m,n;

int lcs(string a, string b){
    m = a.length();
    n = b.length();

    for(int i = 0; i <= m; i++) mem[i][0] = 0;
    for(int j = 0; j <= n; j++) mem[0][j] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]) mem[i][j] = 1 + mem[i-1][j-1];
            else 
                mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
        }
    }

    return mem[m][n];
}

int main(){
    string a, b; 
    cin >> a >> b;
    
    memset(mem, -1, sizeof(mem));
    int answer = lcs(a,b)
    cout << answer << endl;

    //trace 
    stack<int> s;
    for(int i = m-1, j= n-1,k=0; k < answer; k++){
        if(a[i]==b[j] && mem[i][j] == 1 + mem[i-1][j-1]){
            s.push(a[i]);
            --i; --j;
            continue;
        }
        if(mem[i][j] == mem[i-1][j]){
            --i;
            continue;
        }
        if(mem[i][j] == mem[i][j-1]){
            --j;
            continue;
        }
    }
    while(!s.empty()){
        cout << s.back() << " ";
        s.pop();
    }
    return 0;
}
*/