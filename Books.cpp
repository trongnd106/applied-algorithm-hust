#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
int n, t;
int timeRead[10000], sum[10000];

void input(){
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        cin >> timeRead[i];
        if(i == 1) sum[i] = timeRead[i];
        else sum[i] = sum[i-1] + timeRead[i];
    }
}

int binary_search(int *sum, int low, int high, int target){
    if(low > high) 
        return -1;
    int mid = (low+high)/2;
    if(sum[mid] <= target && (mid == high || sum[mid + 1] > target))
        return mid;
    if(sum[mid] > target) return binary_search(sum, low, mid-1, target);
    if(sum[mid] <= target) return binary_search(sum, mid+1, high, target);
}

void solve(){
    int result = INT_MIN;
    for(int i = 1; i <= n; i++){
        // voi moi i, tim chi so j thoa man:
        //  sum[j] - sum[i] + timeRead[i] <= t
        int j = binary_search(sum, i, n, t + sum[i] - timeRead[i]);
        result = max(result, j - i + 1);
    }
    cout << result << endl;
}

int main(){
    input();
    solve();
    return 0;
}