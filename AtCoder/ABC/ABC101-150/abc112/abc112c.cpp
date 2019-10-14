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
  vector<vector<int>> xyh(n, vector<int>(3));
  rep(i, n) cin>>xyh[i][0]>>xyh[i][1]>>xyh[i][2];
  rep(x, 101) rep(y, 101) {
    int h = -1;
    bool good = true;
    rep(i, n) if (xyh[i][2] != 0) {
      int ht = xyh[i][2] + abs(x - xyh[i][0]) + abs(y - xyh[i][1]);
      if (h != -1 and ht != h) good = false;
      h = ht;
    }
    if (good) {
      bool good2 = true;
      rep(i, n) {
        if (xyh[i][2] != max(h - abs(x - xyh[i][0]) - abs(y - xyh[i][1]), 0)) {
          good2 = false;
        }
      }
      if (good2) {
        print(x, y, h);
        return 0;
      }
    }
  }

  return 0;
}