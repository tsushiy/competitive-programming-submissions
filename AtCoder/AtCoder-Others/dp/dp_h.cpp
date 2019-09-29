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

long long dp[1010][1010] = {};

int main() {
  int h, w; cin>>h>>w;
  vector<string> g(h);
  rep(i, h) cin>>g[i];
  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if (i < h-1 and g[i+1][j] != '#') (dp[i+1][j] += dp[i][j]) %= MOD;
    if (j < w-1 and g[i][j+1] != '#') (dp[i][j+1] += dp[i][j]) %= MOD;
  }
  print(dp[h-1][w-1]);
  return 0;
}
