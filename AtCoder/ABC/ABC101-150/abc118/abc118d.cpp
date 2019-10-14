#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, m; cin>>n>>m;
  int b[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<int> a(m);
  rep(i, m) {
    int t; cin>>t; --t;
    a[i] = t;
  }
  sort(a.begin(), a.end(), greater<int>());

  vector<int> dp(n+1, -1);
  dp[0] = 0;
  REP(i, 1, n+1) rep (j, m) {
    if (i - b[a[j]] >= 0 and dp[i - b[a[j]]] != -1) {
      dp[i] = max(dp[i], dp[i - b[a[j]]] + 1);
    }
  }

  string ans = "";
  int cur = n;
  rep(i, dp[n]) {
    rep(j, m) {
      if (cur - b[a[j]] >= 0 and dp[cur-b[a[j]]] == dp[cur]-1) {
        ans += '1' + a[j];
        cur -= b[a[j]];
        break;
      }
    }
  }
  print(ans);

  return 0;
}