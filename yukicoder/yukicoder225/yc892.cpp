#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;
constexpr double EPS = 1e-9;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int a, b, c, d, e, f;
  cin>>a>>b>>c>>d>>e>>f;
  bool flag = true;
  if (a%2==1) flag = !flag;
  if (c%2==1) flag = !flag;
  if (e%2==1) flag = !flag;

  if (flag) print(":-)");
  else print(":-(");

  return 0;
}
