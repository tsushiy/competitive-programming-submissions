#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr long long LLINF = 1LL << 62;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  long long n, a, b; cin>>n>>a>>b;

  long long d = b - a;
  long long l = a-1, r = n-b;
  long long ans = LLINF;

  if (d % 2 == 0) ans = min(ans, d / 2);
  else {
    ans = min(ans, l + 1 + d / 2);
    ans = min(ans, r + 1 + d / 2);
  }

  print(ans);

  return 0;
}