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

int dp[3010][3010] = {};
int main() {
  string s, t; cin>>s>>t;
  rep(i, s.size()) rep(j, t.size()) {
    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(s[i]==t[j]));
    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
  }
  //print(dp[s.size()][t.size()]);

  string ans = "";
  int i = s.size(), j = t.size();
  while (i and j) {
    if (dp[i][j] == dp[i][j-1]) --j;
    else if (dp[i][j] == dp[i-1][j]) --i;
    else {
      ans += s[i-1];
      --i, --j;
    }
  }
  reverse(ans.begin(), ans.end());
  print(ans);
  return 0;
}
