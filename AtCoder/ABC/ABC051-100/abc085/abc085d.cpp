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
  int n, h; cin>>n>>h;
  vector<pair<int, int>> ab(n);
  rep(i, n) cin>>ab[i].first>>ab[i].second;

  sort(ab.begin(), ab.end(), greater<pair<int, int>>());
  int huru = ab[0].first;
  sort(ab.begin(), ab.end(), [](pair<int, int> &x, pair<int, int> &y) {return x.second > y.second;});

  int ans = 0;
  rep(i, n) if (ab[i].second > huru) {
    h -= ab[i].second;
    ++ans;
    if (h <= 0) {
      print(ans);
      return 0;
    }
  }
  ans += h / huru;
  if (h % huru) ++ans;
  print(ans);

  return 0;
}