#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, u, v; cin>>n>>u>>v; --u, --v;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int a, b; cin>>a>>b; --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  vector<int> dt(n, 1e9), da(n, 1e9);
  da[v] = 0, dt[u] = 0;

  queue<int> q;
  q.push(v);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nx: g[cur]) {
      if (da[cur] + 1 < da[nx]) {
        da[nx] = da[cur] + 1;
        q.push(nx);
      }
    }
  }
  q.push(u);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nx: g[cur]) {
      if (dt[cur] + 1 < dt[nx] and da[nx] > dt[cur] + 1) {
        dt[nx] = dt[cur] + 1;
        q.push(nx);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (dt[i] != 1e9) {
      ans = max(ans, da[i] - 1);
    }
  }
  cout << ans << endl;

  return 0;
}