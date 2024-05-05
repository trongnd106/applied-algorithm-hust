// Day con tang dai nhat
// Longest Increase Subsequent

// option 1: recursive
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int a[1000], mem[1000];

int lis(int i){
    if(mem[i] != -1) return mem[i];
    int res = 1;
    for(int j = 0;  j < i; j++){
        if(a[j] < a[i])
            res = max(res, 1 + lis(j));
    }
    mem[i] = res;
    return res;
}

// truy vet
void trace(int i){
    for(int j = 0; j < i; j++){
        if(a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    int maximum = 0;
    memset(mem, -1, sizeof(mem));
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        mem[i] = lis(i);
        maximum = max(maximum, mem[i]);
    }
    cout << maximum << endl;
}

// option2: for loop