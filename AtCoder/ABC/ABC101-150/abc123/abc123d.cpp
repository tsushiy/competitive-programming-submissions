#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int x, y, z, k; cin>>x>>y>>z>>k;
  vector<long long> a(x), b(y), c(z);
  rep(i, x) cin>>a[i];
  rep(i, y) cin>>b[i];
  rep(i, z) cin>>c[i];

  vector<long long> ab;
  rep(i, x) rep(j, y) ab.emplace_back(a[i]+b[j]);
  sort(ab.begin(), ab.end(), greater<long long>());

  vector<long long> abc;
  rep(i, min((int)ab.size(), k)) rep(j, z) abc.emplace_back(ab[i]+c[j]);
  sort(abc.begin(), abc.end(), greater<long long>());

  rep(i, k) print(abc[i]);

  return 0;
}