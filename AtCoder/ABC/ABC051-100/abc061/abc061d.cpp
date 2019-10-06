#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

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
  int n, m; cin>>n>>m;
  vector<vector<pair<int, long long>>> g(n);
  rep(i, m) {
    int a, b;
    long long c;
    cin>>a>>b>>c;
    --a; --b;
    g[a].emplace_back(b, -c);
  }
  auto dists = bellman_ford(g, 0);
  if (dists[n-1] == numeric_limits<long long>::min()) puts("inf");
  else print(-dists[n-1]);
  return 0;
}
