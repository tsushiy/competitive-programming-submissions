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

int main() {
  int n; cin>>n;
  int dp[100010][3];
  rep(i, n) {
    int a, b, c;
    cin>>a>>b>>c;
    if (i==0) {
      dp[i][0] = a;
      dp[i][1] = b;
      dp[i][2] = c;
      continue;
    }
    dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
    dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
  }
  print(max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));
  return 0;
}