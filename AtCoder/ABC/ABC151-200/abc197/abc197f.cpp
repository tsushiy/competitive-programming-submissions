#include <bits/stdc++.h>
using namespace std;
#define REP(i, e) for (int i = 0; i < (e); ++i)
#define REP3(i, b, e) for (int i = (b); i < (e); ++i)
#define RREP(i, b, e) for (int i = (b)-1; i >= e; --i)

inline void print(void) {
  std::cout << '\n';
}

template <class T, class... U>
inline void print(const T &x, const U &...y) {
  std::cout << x;
  if (sizeof...(U) != 0) {
    std::cout << ' ';
  }
  print(y...);
}

template <typename T>
std::vector<T> dijkstra(const std::vector<std::vector<std::pair<int, T>>> &graph, int root) {
  using P = std::pair<T, int>;
  std::vector<T> dists(graph.size(), std::numeric_limits<T>::max());
  dists[root] = 0;

  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  que.emplace(dists[root], root);

  while (!que.empty()) {
    T d;
    int cur;
    std::tie(d, cur) = que.top();
    que.pop();
    if (dists[cur] < d) continue;

    for (auto e : graph[cur]) {
      int nx;
      T cost;
      std::tie(nx, cost) = e;
      if (dists[nx] > dists[cur] + cost) {
        dists[nx] = dists[cur] + cost;
        que.emplace(dists[nx], nx);
      }
    }
  }
  return dists;
}

int n, m;

int encode(int a, int b) {
  return a + b * n;
}

int main() {
  cin >> n >> m;

  vector<int> a(m), b(m);
  vector<char> c(m);
  REP(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i], --b[i];
  }

  // x_1 -> x_2 と y_1 -> y_2 にそれぞれ同じ文字で辺が張られているとき、
  // N^2 頂点のグラフ上で (x_1, y_1) -> (x_2, y_2) という辺を張る
  vector<vector<pair<int, int>>> g(n * n + 1);
  REP(i, m) REP(j, m) {
    if (c[i] != c[j]) continue;
    g[encode(a[i], a[j])].emplace_back(encode(b[i], b[j]), 2);
    g[encode(a[i], b[j])].emplace_back(encode(b[i], a[j]), 2);
    g[encode(b[i], a[j])].emplace_back(encode(a[i], b[j]), 2);
    g[encode(b[i], b[j])].emplace_back(encode(a[i], a[j]), 2);
  }

  int start = encode(0, n - 1);
  int goal = n * n;

  // (v, v) -> goal の辺を張る
  REP(i, n) { g[encode(i, i)].emplace_back(goal, 0); }

  // u <-> v の辺があるとき、 (u, v) -> goal の辺を張る
  REP(i, m) {
    g[encode(a[i], b[i])].emplace_back(goal, 1);
    g[encode(b[i], a[i])].emplace_back(goal, 1);
  }

  auto dists = dijkstra(g, start);
  int ans = dists[goal];

  if (ans == numeric_limits<int>::max()) {
    print(-1);
  } else {
    print(ans);
  }

  return 0;
}
