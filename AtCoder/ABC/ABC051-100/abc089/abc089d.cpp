#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int h, w, d; cin>>h>>w>>d;
  map<int, pair<int, int>> a;
  rep(i, h) rep(j, w) {
    int t; cin>>t;
    a[t] = make_pair(i, j);
  }

  vector<int> b(90010, 0);
  REP(i, 1, d+1) {
    int x = a[i].second, y = a[i].first;
    for (int j = i+d; j < h*w+1; j += d) {
      int nx = a[j].second, ny = a[j].first;
      b[j] = b[j-d] + abs(x-nx) + abs(y-ny);
      x = nx; y = ny;
    }
  }
  int q; cin>>q;
  rep(i, q) {
    int l, r; cin>>l>>r;
    print(b[r]-b[l]);
  }

  return 0;
}