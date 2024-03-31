// Largest Black SubRectangle

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    int res = 0;
    vector<int> hts(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == 0) {
                hts[j] = 0;
            } else {
                hts[j]++;
            }
        }

        stack<int> stk;
        int mx = 0;
        int k = 0;
        while (k < m) {
            if (stk.empty() || hts[k] >= hts[stk.top()]) {
                stk.push(k);
                k++;
            } else {
                int tp = stk.top();
                stk.pop();
                int w = stk.empty() ? k : k - stk.top() - 1;
                mx = max(mx, hts[tp] * w);
            }
        }
        while (!stk.empty()) {
            int tp = stk.top();
            stk.pop();
            int w = stk.empty() ? k : k - stk.top() - 1;
            mx = max(mx, hts[tp] * w);
        }
        res = max(res, mx);
    }

    cout << res << "\n";
}
