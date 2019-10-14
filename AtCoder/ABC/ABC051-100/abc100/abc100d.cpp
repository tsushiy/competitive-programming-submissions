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
  long long ans = 0;
  vector<tuple<long long, long long, long long>> xyz;
  rep(i, n) {
    long long x, y, z; cin>>x>>y>>z;
    xyz.emplace_back(x, y, z);
  }
  rep(i, 2) rep(j, 2) rep(k, 2) {
    vector<long long> t(n);
    rep(l, n) {
      long long a, b, c;
      tie(a, b, c) = xyz[l];
      if (i==1) a = -a;
      if (j==1) b = -b;
      if (k==1) c = -c;
      t[l] = a+b+c;
    }
    sort(t.begin(), t.end(), greater<long long>());
    long long sum = 0;
    rep(l, m) sum += t[l];
    ans = max(ans, sum);
  }
  print(ans);

  return 0;
}