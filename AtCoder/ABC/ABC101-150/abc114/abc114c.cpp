#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int n;
int ans = 0;

void rec(int cur, int digit, int x, int y, int z) {
  if (digit == 0) {
    if (cur <= n and cur >= 1 and x>0 and y>0 and z>0) ++ans;
    return;
  }
  int base = 1;
  rep(j, digit-1) base *= 10;
  if (cur == 0) rec(cur, digit-1, x, y, z);
  rec(cur+7*base, digit-1, x+1, y, z);
  rec(cur+5*base, digit-1, x, y+1, z);
  rec(cur+3*base, digit-1, x, y, z+1);
}

int main() {
  cin>>n;
  int digit = 0;
  for (int m = n; m != 0; m /= 10) ++digit;
  rec(0, digit, 0, 0, 0);
  print(ans);

  return 0;
}