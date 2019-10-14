#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, m; cin>>n>>m;
  vector<pair<int, int>> ab;
  rep(i, m) {
    int a, b; cin>>a>>b;
    ab.emplace_back(a, b);
  }
  sort(ab.begin(), ab.end(), [](auto &a, auto &b){return (a.second < b.second);});

  int ans = 0;
  int cur = -1;
  rep(i, m) {
    if (cur <= ab[i].first) {
      ++ans;
      cur = ab[i].second;
    }
  }
  print(ans);

  return 0;
}
