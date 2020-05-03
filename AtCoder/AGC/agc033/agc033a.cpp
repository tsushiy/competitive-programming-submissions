#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int h, w; cin>>h>>w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) cin>>a[i];

  vector<vector<int>> cost(h, vector<int>(w, 1e9));
  queue<int> q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        cost[i][j] = 0;
        q.push(i*w + j);
      }
    }
  }

  while (!q.empty()) {
    int m = q.front(); q.pop();
    int y = m / w, x = m % w;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx and nx < w and 0 <= ny and ny < h) {
        if (cost[y][x] + 1 < cost[ny][nx]) {
          cost[ny][nx] = cost[y][x] + 1;
          q.push(ny*w + nx);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ans = max(ans, cost[i][j]);
    }
  }
  cout << ans << endl;

  return 0;
}