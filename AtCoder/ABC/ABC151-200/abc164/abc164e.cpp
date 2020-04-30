#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int silverAndPos2Node(int silver, int pos) {
  return silver * 50 + pos;
}

template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>> &graph, int root) {
  using P = pair<T, int>;
  vector<T> dists(graph.size(), numeric_limits<T>::max());
  priority_queue<P, vector<P>, greater<P>> que;
  dists[root] = 0;
  que.emplace(dists[root], root);
  while (!que.empty()) {
    T d; int cur;
    tie(d, cur) = que.top(); que.pop();
    if (dists[cur] < d) continue;
    for (auto e : graph[cur]) {
      int nx; T cost;
      tie(nx, cost) = e;
      if (dists[nx] > dists[cur] + cost) {
        dists[nx] = dists[cur] + cost;
        que.emplace(dists[nx], nx);
      }
    }
  }
  return dists;
}


int main() {
  int n, m, s; cin>>n>>m>>s;
  s = min(2500, s);

  vector<vector<pair<int, long long>>> graph(2510*50+50); // <node, time>
  rep(i, m) {
    int u, v, a; long long b;
    cin >> u >> v >> a >> b;
    --u;--v;
    RREP(j, 2501, 0) if (j - a >= 0) {
      int root = silverAndPos2Node(j, u);
      int target = silverAndPos2Node(j-a, v);
      graph[root].emplace_back(target, b);
    }
    RREP(j, 2501, 0) if (j - a >= 0) {
      int root = silverAndPos2Node(j, v);
      int target = silverAndPos2Node(j-a, u);
      graph[root].emplace_back(target, b);
    }
  }
  rep(i, n) {
    long long c, d; cin>>c>>d;
    rep(j, 2501) {
      int root = silverAndPos2Node(j, i);
      int target = silverAndPos2Node(int(min(2500LL, j+c)), i);
      graph[root].emplace_back(target, d);
    }
  }

  auto dists = dijkstra(graph, silverAndPos2Node(s, 0));
  REP(i, 1, n) {
    long long ans = 1e18;
    rep(j, 2501) {
      ans = min(ans, dists[silverAndPos2Node(j, i)]);
    }
    print(ans);
  }

  return 0;
}