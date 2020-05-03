#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> bellman_ford(const vector<vector<pair<int, T>>> &graph, int root) {
  int n = graph.size();
  vector<T> dists(n, numeric_limits<T>::max());
  dists[root] = 0;
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dists[j] == numeric_limits<T>::max()) continue;
      for (auto e : graph[j]) {
        int nx; T cost;
        tie(nx, cost) = e;
        if (dists[nx] > dists[j] + cost) dists[nx] = dists[j] + cost;
      }
    }
  }

  queue<int> q;
  for (int i = 0; i < n; ++i) if (dists[i] != numeric_limits<T>::max()) q.push(i);
  while (!q.empty()) {
    int i = q.front(); q.pop();
    for (auto e : graph[i]) {
      int nx; T cost;
      tie(nx, cost) = e;
      if (dists[nx] == numeric_limits<T>::min()) continue;
      if (dists[i] == numeric_limits<T>::min() or dists[nx] > dists[i] + cost) {
        dists[nx] = numeric_limits<T>::min();
        q.push(nx);
      }
    }
  }
  return dists;
}

int main() {
  int n, m, p; cin>>n>>m>>p;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b, c; cin>>a>>b>>c;
    --a; --b;
    g[a].emplace_back(b, -c+p);
  }

  auto dists = bellman_ford(g, 0);
  if (dists[n-1] == numeric_limits<int>::min()) {
    cout << -1 << endl;
  } else {
    cout << max(0, -dists[n-1]) << endl;
  }

  return 0;
}