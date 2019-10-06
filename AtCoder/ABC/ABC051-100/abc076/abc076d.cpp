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

int main() {
  int n; cin>>n;
  vector<int> t(n), v(n);
  rep(i, n) cin>>t[i];
  rep(i, n) cin>>v[i];
  int T = 0;
  rep(i, n) T += t[i];
  vector<int> ub(2*T+1, INF);

  int x = 0;
  rep(i, n) rep(tt, t[i]) {
    ub[x] = min(ub[x], v[i]*2);
    ub[x+1] = min(ub[x+1], v[i]*2);
    ub[x+2] = min(ub[x+2], v[i]*2);
    x += 2;
  }
  ub[0] = ub[T*2] = 0;
  rep(x, 2*T) ub[x+1] = min(ub[x+1], ub[x] + 1);
  RREP(x, 2*T, 0) ub[x] = min(ub[x], ub[x+1] + 1);

  double ans = 0;
  rep(x, 2*T) ans += (ub[x] + ub[x+1]) / 2.0;
  cout << fixed << setprecision(10) << ans / 4 << endl;

  return 0;
}
