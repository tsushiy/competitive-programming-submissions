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
  string s;
  if (n==0) s = '0';
  while (n != 0) {
    int rem = n % -2;
    n /= -2;
    if (rem < 0) {
      rem *= -1;
      n += 1;
    }
    s += ('0' + rem);
  }
  reverse(s.begin(), s.end());
  print(s);

  return 0;
}