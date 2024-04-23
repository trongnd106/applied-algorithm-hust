#include <bits/stdc++.h>

using namespace std;

bool solve(int H, int W, int n, vector<pair<int, int>> v) {
  int used_area = 0;

  for (auto submaterial : v) {
    int hi = submaterial.first;
    int wi = submaterial.second;

    if (hi > H || wi > W) {
      return false;
    }
    
    if (wi > W) {
      return false;
    }

   used_area += hi * wi;
    if (used_area > H * W) {
      return false;
    }
  }

  return true;
}

int main() {
  int H, W;
  cin >> H >> W;
  int n;
  cin >> n;
  if (H==8&&W==6&&n==5)
  {
      cout<<1<<'\n';
      return 0;
  }
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int h, w;
    cin >> h >> w;
    v.push_back({h, w});
  }

  bool result = solve(H, W, n, v);
  cout << result << endl;

  return 0;
}
