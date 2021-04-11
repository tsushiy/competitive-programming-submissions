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

int n;
map<int, int> ma;
vector<int> c;
vector<vector<int>> g;
vector<int> ans;

void rec(int par, int cur) {
  if (ma[c[cur]] == 1) ans.emplace_back(cur);

  for (auto nx : g[cur]) {
    if (nx == par) continue;
    ++ma[c[nx]];
    rec(cur, nx);
    --ma[c[nx]];
  }
}

int main() {
  cin >> n;
  c.resize(n);
  REP(i, n) cin >> c[i];
  g.resize(n);
  REP(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  ++ma[c[0]];
  rec(-1, 0);
  sort(ans.begin(), ans.end());
  REP(i, ans.size()) { print(ans[i] + 1); }

  return 0;
}
