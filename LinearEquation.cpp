// Count solutions to an integer linear equation like:
//   a1.x1 + x2.x2 + ... + an.xn = M

#include <iostream>
#include <vector>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

using namespace std;

ll n, M;
vector<ll> a;
ll cnt = 0;

void calculate(vector<ll> &sol, ll w, ll idx) {
    if (w == 0) {
        if (idx == n){
            ++cnt;
        }
        return;
    }
    if (idx >= n) {
        return;
    }
    for (int i = 1; i <= w / a[idx]; ++i) {
        if (a[idx] * i <= w) {
            sol.emplace_back(i);
            calculate(sol, w - a[idx] * i, idx + 1);
            // backtrack
            sol.pop_back();
        }  
    }
}

void solve() {
    cin >> n >> M;
    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        a.emplace_back(tmp);
    }
    vector<ll> sol;
    calculate(sol, M, 0);
    cout << cnt << "\n";
}

int main() {
    fast_cin();
    solve();
    return 0;
}
