#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, m, q; cin>>n>>m>>q;
  vector<vector<int>> lr(n+1, vector<int>(n+1, 0));
  rep(i, m) {
    int l, r; cin>>l>>r;
    ++lr[l][r];
  }

  rep(i, n) rep(j, n) lr[i+1][j+1] += lr[i][j+1] + lr[i+1][j] - lr[i][j];
  rep(i, q) {
    int l, r; cin>>l>>r;
    print(lr[r][r] - lr[l-1][r] - lr[r][l-1] + lr[l-1][l-1]);
  }

  return 0;
}