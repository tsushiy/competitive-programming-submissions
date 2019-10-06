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

int c[10][10];
int mins[10];
bool used[10] = {};

int rec(int x) {
  if (x == 1) return 0;

  int ret = INF;
  rep(nx, 10) if (nx != x and used[nx] == false) {
    used[nx] = true;
    ret = min(ret, c[x][nx] + rec(nx));
    used[nx] = false;
  }
  return ret;
}

int main() {
  int h, w; cin>>h>>w;
  rep(i, 10) rep(j, 10) cin>>c[i][j];
  rep(i, 10) {
    used[i] = true;
    mins[i] = rec(i);
    used[i] = false;
  }
  int ans = 0;
  rep(i, h) rep(j, w) {
    int t; cin>>t;
    if (t != -1) ans += mins[t];
  }
  print(ans);

  return 0;
}
