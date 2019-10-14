#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int INF = 1LL << 30;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, c; cin>>n>>c;
  int d[30][30];
  rep(i, c) rep(j, c) cin>>d[i][j];

  int a[3][30] = {};
  rep(i, n) rep(j, n) {
    int ct; cin>>ct; --ct;
    rep(k, c) a[(i+j)%3][k] += d[ct][k];
  }

  int ans = INF;
  rep(i, c) rep(j, c) rep(k, c) {
    if (i==j || j==k || k==i) continue;
    ans = min(ans, a[0][i]+a[1][j]+a[2][k]);
  }
  print(ans);

  return 0;
}