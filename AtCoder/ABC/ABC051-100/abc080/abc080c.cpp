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

int f[110][10];
int p[110][11];

int main() {
  int n; cin>>n;
  rep(i, n) rep(j, 10) cin>>f[i][j];
  rep(i, n) rep(j, 11) cin>>p[i][j];

  int ans = -INF;
  REP(i, 1, 1<<10) {
    int ret = 0;
    rep(j, n) {
      int cnt = 0;
      rep(k, 10) if (i & (1<<k) and f[j][k]) ++cnt;
      ret += p[j][cnt];
    }
    ans = max(ans, ret);
  }
  print(ans);

  return 0;
}
