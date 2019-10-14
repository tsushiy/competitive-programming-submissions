#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int n, a, b, c;
vector<int> l(10);
int ans = 1<<30;

void rec(int cur, int sum, int x, int y, int z) {
  if (cur == n) {
    if (x > 0 and y > 0 and z > 0) {
      ans = min(ans, sum + abs(a-x) + abs(b-y) + abs(c-z) - 30);
    }
    return;
  }
  rec(cur+1, sum, x, y, z);
  rec(cur+1, sum+10, x+l[cur], y, z);
  rec(cur+1, sum+10, x, y+l[cur], z);
  rec(cur+1, sum+10, x, y, z+l[cur]);
}

int main() {
  cin>>n>>a>>b>>c;
  rep(i, n) cin>>l[i];
  rec(0, 0, 0, 0, 0);
  print(ans);

  return 0;
}