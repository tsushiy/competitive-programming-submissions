#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

template<typename T>
vector<vector<T>> warshall_floyd(const vector<vector<pair<int, T>>> &graph) {
  int n = graph.size();
  vector<vector<T>> dists(n, vector<T>(n, numeric_limits<T>::max()));
  for (int i = 0; i < n; ++i) {
    dists[i][i] = 0;
    for (auto e : graph[i]) {
      int nx; T cost;
      tie(nx, cost) = e;
      dists[i][nx] = cost;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) if (dists[i][k] != numeric_limits<T>::max()) {
      for (int j = 0; j < n; ++j) if (dists[k][j] != numeric_limits<T>::max()) {
        dists[i][j] = min(dists[i][j], dists[i][k]+dists[k][j]);
      }
    }
  }
  return dists;
}

int main() {
  int n, m;
  long long l;
  cin>>n>>m>>l;

  vector<vector<pair<int, long long>>> g(n);
  rep(i, m) {
    int a, b; long long c;
    cin>>a>>b>>c;
    --a; --b;
    if (c <= l) {
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
  }
  auto dists = warshall_floyd(g);

  vector<vector<pair<int, long long>>> g2(n);
  rep(i, n) REP(j, i, n) {
    if (dists[i][j] <= l) {
      g2[i].emplace_back(j, 1);
      g2[j].emplace_back(i, 1);
    }
  }
  auto dists2 = warshall_floyd(g2);

  int q; cin>>q;
  rep(i, q) {
    int s, t; cin>>s>>t;
    --s; --t;
    if (dists2[s][t] == numeric_limits<long long>::max()) print(-1);
    else print(dists2[s][t]-1);
  }

  return 0;
}