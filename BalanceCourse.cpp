// Balanced Courses Assignments
// this solve accepted 4/5, final test TLE
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<vector<int>> prefer;
vector<vector<int>> conflict;
vector<int> teacher_load;
vector<int> teach_list;
int minofMax;

bool isAssignable(int course, int teacher) {   // O(N)  -> tối ưu ?
    if (find(prefer[teacher].begin(), prefer[teacher].end(), course) == prefer[teacher].end())  //O(N)
        return false;
    
    for (int i = 1; i <= n; ++i) {    // O(N)
        if (teacher_load[i] == teacher && conflict[course][i])
            return false;
    }

    return true;
}


void Try(int k) {
    if (k == n + 1) {
        int currMax = *max_element(teach_list.begin(), teach_list.end());  
        minofMax = min(minofMax, currMax);
        return;
    }

    for (int teacher = 1; teacher <= m; ++teacher) {
        if (isAssignable(k, teacher)) {
            teacher_load[k] = teacher;
            teach_list[teacher]++;

            int newMax = *max_element(teach_list.begin(), teach_list.end());   // O(N)

            if (newMax > minofMax) {
                teach_list[teacher]--; // backtrack
                teacher_load[k] = 0;
                return;
            } else {
                Try(k + 1);
            }

            // backtrack
            teach_list[teacher]--;
            teacher_load[k] = 0;
        }
    }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    // input
    cin >> m >> n;
    prefer.resize(m + 1);
    teacher_load.resize(n + 1);
    teach_list.resize(n + 1);
    int k;
    for (int teacher = 1; teacher <= m; ++teacher) {
        cin >> k;
        prefer[teacher].resize(k);
        for (int i = 0; i < k; ++i) {
            cin >> prefer[teacher][i];
        }
    }
    conflict.resize(n + 1, vector<int>(n + 1, 0));
    cin >> k;
    int course1, course2;
    for (int i = 0; i < k; ++i) {
        cin >> course1 >> course2;
        conflict[course1][course2] = 1;
        conflict[course2][course1] = 1;
    }
    minofMax = 1e8;

    Try(1);
    cout << minofMax << endl;
    return 0;
}
