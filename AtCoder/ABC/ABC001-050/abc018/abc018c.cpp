#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int r, c, k; cin>>r>>c>>k;
  vector<string> s(r);
  rep(i, r) cin>>s[i];

  vector<vector<int>> up(r, vector<int>(c, 0));
  vector<vector<int>> down(r, vector<int>(c, 0));
  rep(i, c) if (s[0][i] == 'o') up[0][i] = 1;
  rep(i, c) if (s[r-1][i] == 'o') down[r-1][i] = 1;
  REP(i, 1, r) rep(j, c) if (s[i][j] == 'o') up[i][j] = up[i-1][j] + 1;
  RREP(i, r-1, 0) rep(j, c) if (s[i][j] == 'o') down[i][j] = down[i+1][j] + 1;

  int ans = 0;
  rep(i, r) rep(j, c) if (j-k+1 >= 0 and j+k-1 <= c-1) {
    if (up[i][j] >= k and down[i][j] >= k) {
      bool ok = true;
      REP(l, j-k+1, j+k) if (!(up[i][l] >= k - abs(j-l) and down[i][l] >= k - abs(j-l))) ok = false;
      ans += ok;
    }
  }
  print(ans);

  return 0;
}