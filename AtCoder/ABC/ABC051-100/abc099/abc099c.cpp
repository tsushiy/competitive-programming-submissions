#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n; cin>>n;
  int dp[100010];
  rep(i, 100010) dp[i] = i;
  for (int i = 6; i < 100010; i *= 6) {
    for (int j = 0; j+i < 100010; ++j) dp[j+i] = min(dp[j+i], dp[j]+1);
  }
  for (int i = 9; i < 100010; i *= 9) {
    for (int j = 0; j+i < 100010; ++j) dp[j+i] = min(dp[j+i], dp[j]+1);
  }
  print(dp[n]);
  return 0;
}