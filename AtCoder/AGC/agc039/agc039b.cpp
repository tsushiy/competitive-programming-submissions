#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int n;
vector<vector<int>> g(210);
vector<int> col(210, 0);

bool is_bipartite(int x, int c) {
  col[x] = c;
  for (auto nx: g[x]) {
    if (col[nx] == c) return false;
    if (col[nx] == 0 && !is_bipartite(nx, -c)) return false;
  }
  return true;
}

int main() {
  cin>>n;
  rep(i, n) rep(j, n) {
    char t; cin>>t;
    if (t == '1') g[i].emplace_back(j);
  }

  bool check = is_bipartite(0, 1);
  if (!check) {
    print(-1);
    return 0;
  }

  int ans = 0;
  rep(i, n) {
    vector<int> dists(n, INF);
    dists[i] = 1;
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (auto nx: g[x]) {
        if (dists[nx] > dists[x] + 1) {
          dists[nx] = dists[x] + 1;
          q.push(nx);
        }
      }
    }
    ans = max(ans, *max_element(dists.begin(), dists.end()));
  }
  print(ans);

  return 0;
}
