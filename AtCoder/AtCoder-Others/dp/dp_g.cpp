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

vector<vector<int>> g(100010);
int dp[100010];

int rec(int x) {
  if (dp[x] != -1) return dp[x];
  dp[x] = 0;
  for (auto y : g[x]) {
    dp[x] = max(dp[x], rec(y)+1);
  }
  return dp[x];
}

int main() {
  int n, m; cin>>n>>m;
  rep(i, 100010) dp[i] = -1;
  rep(i, m) {
    int x, y; cin>>x>>y;
    g[x].push_back(y);
  }
  int ans = 0;
  rep(i, 100010) ans = max(ans, rec(i));
  print(ans);

  return 0;
}
