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
  vector<int> c(n);
  rep(i, n) cin>>c[i];

  double ans = 0;
  rep(i, n) {
    int cnt = 0;
    rep(j, n) if (i != j and c[i]%c[j] == 0) ++cnt;
    if (cnt % 2 == 1) ans += (double)1/2;
    else ans += (double)(cnt+2)/(2*cnt+2);
  }
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}