#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

vector<vector<pair<int, long long>>> g(100010);
vector<long long> dists(100010, LLINF);

void bfs(int root) {
  queue<int> que;
  que.push(root);
  while (!que.empty()) {
    int x = que.front(); que.pop();
    for (auto e: g[x]) {
      int nx; long long cost;
      tie(nx, cost) = e;
      if (dists[nx] > dists[x] + cost) {
        dists[nx] = dists[x] + cost;
        que.push(nx);
      }
    }
  }
}

int main() {
  int n; cin>>n;
  rep(i, n-1) {
    int a, b, c; cin>>a>>b>>c;
    --a; --b;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  int q, k; cin>>q>>k;
  --k;
  dists[k] = 0;
  bfs(k);
  rep(i, q) {
    int x, y; cin>>x>>y;
    --x; --y;
    print(dists[x]+dists[y]);
  }

  return 0;
}
