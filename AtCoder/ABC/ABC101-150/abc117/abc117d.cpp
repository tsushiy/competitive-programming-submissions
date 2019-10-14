#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n; long long k; cin>>n>>k;
  vector<vector<int>> b(45, vector<int>(2, 0));
  rep(i, n) {
    long long a; cin>>a;
    rep(j, 45) ++b[j][(a>>j) & 1];
  }

  long long dp[45][2];
  rep(i, 45) rep(j, 2) dp[i][j] = -1;
  dp[44][0] = 0;

  RREP(i, 44, 0) {
    long long mask = (1LL<<i);
    if (dp[i+1][0] != -1) {
      if (k & (1LL<<i)) {
        dp[i][0] = max(dp[i][0], dp[i+1][0] + mask * b[i][0]);
        dp[i][1] = max(dp[i][1], dp[i+1][0] + mask * b[i][1]);
      } else {
        dp[i][0] = max(dp[i][0], dp[i+1][0] + mask * b[i][1]);
      }
    }
    if (dp[i+1][1] != -1) {
      dp[i][1] = max(dp[i][1], dp[i+1][1] + mask * (max(b[i][0], b[i][1])));
    }
  }
  print(max(dp[0][0], dp[0][1]));

  return 0;
}