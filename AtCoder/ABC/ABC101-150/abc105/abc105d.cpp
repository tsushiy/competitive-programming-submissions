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
  vector<long long> a(n);
  rep(i, n) cin>>a[i];

  vector<int> acc(n);
  acc[0] = a[0] % m;
  rep(i, n-1) acc[i+1] = (acc[i] + a[i+1]) % m;

  map<int, long long> b;
  rep(i, n) ++b[acc[i]];
  long long ans = 0;
  ans += b[0];
  for (auto x: b) {
    ans += x.second * (x.second - 1) / 2;
  }
  print(ans);

  return 0;
}