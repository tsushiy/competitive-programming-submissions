#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, C; cin>>n>>C;
  vector<int> t(100010);
  vector<vector<int>> cst(n, vector<int>(3));
  rep(i, n) {
    cin>>cst[i][1]>>cst[i][2]>>cst[i][0];
    --cst[i][1]; --cst[i][2];
  }
  sort(cst.begin(), cst.end());
  REP(j, cst[0][1], cst[0][2]+1) ++t[j];
  REP(i, 1, n) {
    REP(j, cst[i][1], cst[i][2]+1) {
      if (cst[i-1][0] == cst[i][0] and cst[i-1][2] == cst[i][1] and j == cst[i][1]) continue;
      ++t[j];
    }
  }

  int ans = 0;
  rep(i, 100010) ans = max(ans, t[i]);
  print(ans);

  return 0;
}
