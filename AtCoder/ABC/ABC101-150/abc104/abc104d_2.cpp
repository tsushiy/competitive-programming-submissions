#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  string s; cin>>s;
  int n = s.size();

  vector<vector<long long>> dp(n+1, vector<long long>(4, 0));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 4) {
      if (s[i] != '?') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
      else dp[i+1][j] = (dp[i+1][j] + dp[i][j] * 3) % MOD;
    }
    if (s[i] == 'A' or s[i] == '?') dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % MOD;
    if (s[i] == 'B' or s[i] == '?') dp[i+1][2] = (dp[i+1][2] + dp[i][1]) % MOD;
    if (s[i] == 'C' or s[i] == '?') dp[i+1][3] = (dp[i+1][3] + dp[i][2]) % MOD;
  }
  print(dp[n][3]);
  return 0;
}
