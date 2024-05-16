// accepted 5/5

#include <bits/stdc++.h>

using namespace std;

int total[1005] = {}, n, k1, k2, temp = 0;

int main(){
    cin >> n >> k1 >> k2;
    ++k1; ++k2;
    for(int i = k1; i <= k2; ++i)
        total[i] = 1;
    for(int i = 1; i <= k2 + 1 - k1; ++i)
        temp += total[i];
    for(int i = k2 + 1; i <= n + 1; ++i){
        total[i] = temp;
        temp -= total[i - k2];
        temp += total[i - k1 + 1];
    }
    cout << total[n - 1] + 2 * total[n] + total[n + 1];
}
