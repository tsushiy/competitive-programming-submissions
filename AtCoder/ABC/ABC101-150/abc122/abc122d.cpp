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
  int n; cin>>n;
  long long dp[110][4][4][4] = {}; // A:0, G:1, C:2, T:3
  rep(x, 4) rep(y, 4) rep(z, 4) dp[0][x][y][z] = 1;
  dp[0][2][1][0] = dp[0][2][0][1] = dp[0][1][2][0] = 0;

  rep(i, n) rep(j, 4) rep(x, 4) rep(y, 4) rep(z, 4) {
    if (j==2 and x==1 and y==0) continue;
    if (j==2 and x==0 and y==1) continue;
    if (j==1 and x==2 and y==0) continue;
    if (j==2 and x==1 and z==0) continue;
    if (j==2 and y==1 and z==0) continue;
    dp[i+1][j][x][y] = (dp[i+1][j][x][y] + dp[i][x][y][z]) % MOD;
  }
  print(dp[n][3][3][3]);

  return 0;
}