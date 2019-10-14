#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int d, g; cin>>d>>g;
  vector<tuple<int, int, int>> pc;
  rep(i, d) {
    int p, c; cin>>p>>c;
    pc.emplace_back(p, c, (i+1)*100*p + c);
  }

  int ans = 1000;

  rep(i, d) {
    rep(j, 1<<10) {
      int sum = 0;
      int cnt = 0;  
      rep(k, d) if (k != i) {
        if (j & (1<<k)) {
          sum += get<2>(pc[k]);
          cnt += get<0>(pc[k]);
        }
      }
      if (sum >= g) ans = min(ans, cnt);
      rep(k, get<0>(pc[i])) {
        sum += (i+1)*100;
        ++cnt;
        if (sum >= g) ans = min(ans, cnt);
      }
      sum += get<1>(pc[i]);
      if (sum >= g) ans = min(ans, cnt);
    }
  }
  print(ans);

  return 0;
}