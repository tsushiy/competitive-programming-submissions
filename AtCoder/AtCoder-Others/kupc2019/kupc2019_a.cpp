#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, x; cin>>n>>x;
  vector<int> a(n);
  rep(i, n) cin>>a[i];
  int ma = *max_element(a.begin(), a.end());
  int ans = 0;
  rep(i, n) if (a[i] + x >= ma) ++ans;
  print(ans);

  return 0;
}