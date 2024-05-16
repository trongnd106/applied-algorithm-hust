// Longest path on an undirected tree
// accepted 5/5

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

int N;
vector<vector<pair<int, int>>> Adj;
int dis[100005];

pair<int, int> BFS(int s) {
    for (int v = 1; v <= N; v++) dis[v] = -1;
    queue<int> Q; Q.push(s); dis[s] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto edge : Adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dis[v] == -1) {
                Q.push(v);
                dis[v] = dis[u] + weight;
            }
        }
    }
    int maxD = -1;
    int indexN;
    for (int i = 1; i <= N; i++) { // Duyệt qua tất cả các đỉnh từ 1 đến N
        if (maxD < dis[i]) {
            maxD = dis[i];
            indexN = i;
        }
    }
    return make_pair(indexN, maxD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    Adj.resize(N + 1); // Tạo kích thước phù hợp cho Adj
    for (int i = 1; i < N; i++) { // Đọc vào N-1 cạnh
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].emplace_back(v, w);
        Adj[v].emplace_back(u, w);
    }
    memset(dis, -1, sizeof(dis));
    pair<int, int> firstBFS = BFS(1);
    pair<int, int> secondBFS = BFS(firstBFS.first);
    cout << secondBFS.second << endl;
    return 0;
}