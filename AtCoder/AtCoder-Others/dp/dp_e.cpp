#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

long long dp[110][200010];
int main() {
  int n, w; cin>>n>>w;
  rep(i, 110) rep(j, 100010) dp[i][j] = LLINF;
  dp[0][0] = 0;
  rep(i, n) {
    int wt, v; cin>>wt>>v;
    rep(j, 100010) {
      dp[i+1][j+v] = min(dp[i+1][j+v], dp[i][j] + wt);
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
    }
  }
  RREP(i, 100010, 0) {
    if (dp[n][i] <= w) {
      print(i);
      return 0;
    }
  }
  return 0;
}
