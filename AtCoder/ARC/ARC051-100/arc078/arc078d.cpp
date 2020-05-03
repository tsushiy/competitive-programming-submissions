#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int a, b; cin>>a>>b; --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  vector<int> df(n, 1e9), ds(n, 1e9);
  df[0] = 0, ds[n-1] = 0;

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nx: g[cur]) {
      if (df[cur] + 1 < df[nx] and nx != n-1) {
        df[nx] = df[cur] + 1;
        q.push(nx);
      }
    }
  }
  q.push(n-1);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto nx: g[cur]) {
      if (ds[cur] + 1 < ds[nx] and df[nx] > ds[cur] + 1) {
        ds[nx] = ds[cur] + 1;
        df[nx] = 1e9;
        q.push(nx);
      }
    }
  }

  int b = 0, w = 0;
  for (int i = 0; i < n; i++) {
    if (df[i] != 1e9) ++b;
    if (ds[i] != 1e9) ++w;
  }

  if (b > w) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }

  return 0;
}