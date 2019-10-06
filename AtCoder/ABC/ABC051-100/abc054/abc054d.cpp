#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, ma, mb; cin>>n>>ma>>mb;
  int ans = INF;
  int dp[410][410];
  rep(i, 410) rep(j, 410) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i, n) {
    int a, b, c; cin>>a>>b>>c;
    RREP(j, 410-a, 0) RREP(k, 410-b, 0) {
      if (dp[j][k] != INF) {
        dp[j+a][k+b] = min(dp[j+a][k+b], dp[j][k]+c);
        if ((j+a)*mb == (k+b)*ma) ans = min(ans, dp[j+a][k+b]);
      }
    }
  }
  if (ans == INF) print(-1);
  else print(ans);

  return 0;
}
