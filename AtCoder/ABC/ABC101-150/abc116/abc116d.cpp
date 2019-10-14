#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n, k; cin>>n>>k;
  vector<pair<int, int>> td(n);
  rep(i, n) cin>>td[i].first>>td[i].second;
  sort(td.begin(), td.end(), [](auto x, auto y) { return x.second > y.second; });

  long long ans = 0, cur = 0;
  set<int> s;
  stack<int> q;
  rep(i, k) {
    if (s.count(td[i].first)) q.push(td[i].second);
    s.emplace(td[i].first);
    cur += td[i].second;
  }
  ans = cur + s.size() * s.size();

  REP(i, k, n) {
    if (q.empty()) break;
    if (s.count(td[i].first)) continue;
    cur -= q.top(); q.pop();
    cur += td[i].second;
    s.emplace(td[i].first);
    ans = max(ans, cur + (long long)(s.size() * s.size()));
  }
  print(ans);

  return 0;
}