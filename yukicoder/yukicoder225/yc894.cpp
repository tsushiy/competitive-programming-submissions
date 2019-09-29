#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

template<typename T>
T gcd(T a, T b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

template<typename T>
T lcm(T a, T b) {
  T ret = a / gcd(a, b) * b;
  if (b <= numeric_limits<T>::max() / (a / gcd(a, b))) return ret;
  else return numeric_limits<T>::max();
}

int main() {
  long long t, a, b; cin>>t>>a>>b;
  long long ans = 0;
  long long l = lcm(a, b);
  ans += (t-1)/a + (t-1)/b + 1;
  ans -= (t-1)/l;
  print(ans);

  return 0;
}
