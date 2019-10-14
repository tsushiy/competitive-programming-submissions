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
  vector<int> a(n);
  rep(i, n) cin>>a[i];
  sort(a.begin(), a.end(), [](auto x, auto y){ return abs(x) > abs(y); });

  bool good = true;
  rep(i, n) if (a[i] < 0) good = !good;

  long long ans = 0;
  if (good) rep(i, n) ans += abs(a[i]);
  else {
    rep(i, n-1) ans += abs(a[i]);
    ans -= abs(a[n-1]);
  }
  print(ans);

  return 0;
}