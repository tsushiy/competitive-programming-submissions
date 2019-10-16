#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int R, C, k; cin>>R>>C>>k;
  int n; cin>>n;

  vector<int> row(100010, 0), col(100010, 0);
  vector<int> r(n), c(n);
  rep(i, n) {
    cin>>r[i]>>c[i];
    ++row[r[i]]; ++col[c[i]];
  }

  vector<int> rowt(100010, 0), colt(100010, 0);
  rep(i, R) ++rowt[row[i+1]];
  rep(i, C) ++colt[col[i+1]];

  long long ans = 0;
  rep(i, k+1) ans += (long long)rowt[i]*colt[k-i];
  rep(i, n) {
    if (row[r[i]] + col[c[i]] == k) --ans;
    if (row[r[i]] + col[c[i]] == k+1) ++ans;
  }
  print(ans);
  
  return 0;
}