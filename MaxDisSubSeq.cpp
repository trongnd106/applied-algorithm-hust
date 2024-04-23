// Max Distance Sub-Sequence 
// 04/2024 - accepted 4/5 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        sort(s.begin(), s.end());

        int low = 0, high = s[n - 1] - s[0];
        int maxDistance = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int placed = 1;
            int lastPosition = s[0];
            for (int i = 1; i < n; ++i) {
                if (s[i] - lastPosition >= mid) {
                    lastPosition = s[i];
                    placed++;
                }
            }
            if (placed >= c) {
                maxDistance = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << maxDistance << endl;
    }
    return 0;
}
