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
long long x[50], y[50];

int check(long long xma, long long xmi, long long yma, long long ymi) {
  int ret = 0;
  rep(k, n) {
    if (xmi <= x[k] and x[k] <= xma and ymi <= y[k] and y[k] <= yma) ++ret;
  }
  return ret;
}

int main() {
  int K; cin>>n>>K;
  rep(i, n) cin>>x[i]>>y[i];
  long long ans = LLINF;
  rep(i, n) rep(j, n) rep(k, n) rep(l, n) {
    long long xma, xmi, yma, ymi;
    xma = max(x[i], x[j]); xmi = min(x[i], x[j]);
    yma = max(y[k], y[l]); ymi = min(y[k], y[l]);
    if (check(xma, xmi, yma, ymi) >= K) ans = min(ans, (xma-xmi) * (yma-ymi));
  }
  print(ans);

  return 0;
}
