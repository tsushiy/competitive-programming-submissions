#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

long long f(long long x) {
  if (x % 4 == 0) return x;
  else if (x % 4 == 1) return 1;
  else if (x % 4 == 2) return x+1;
  else return 0;
}

int main() {
  long long a, b; cin>>a>>b;
  print(f(a-1)^f(b));

  return 0;
}