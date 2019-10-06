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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int h, w;
char g[55][55];
int dists[55][55];

void bfs() {
  rep(i, h) rep(j, w) dists[i][j] = INF;
  dists[0][0] = 1;
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    int x, y;
    tie(y, x) = q.front(); q.pop();
    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (dists[ny][nx] != INF or nx < 0 or w <= nx or ny < 0 or h <= ny) continue;
      if (g[ny][nx] == '#') continue;
      dists[ny][nx] = dists[y][x] + 1;
      q.emplace(ny, nx);
    }
  }
}

int main() {
  cin>>h>>w;
  rep(i, h) rep(j, w) cin>>g[i][j];

  int bs = 0;
  rep(i, h) rep(j, w) if (g[i][j] == '#') ++bs;
  bfs();

  int dist = dists[h-1][w-1];
  if (dist == INF) print(-1);
  else print(h*w - dist - bs);

  return 0;
}