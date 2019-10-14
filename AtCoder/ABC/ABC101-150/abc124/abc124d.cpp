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
  string s; cin>>s;
  vector<int> a;

  a.emplace_back(0);
  if (s[0] == '0') a.emplace_back(0);

  int cur = 1;
  REP(i, 1, n) {
    if (s[i] == s[i-1]) ++cur;
    else {
      a.emplace_back(cur);
      cur = 1;
    }
  }
  a.emplace_back(cur);
  rep(i, 3*k) a.emplace_back(0);
  rep(i, a.size()-1) a[i+1] += a[i];

  int ans = 0;
  for (int i = 1; i+2*k < a.size(); i += 2) {
    ans = max(ans, a[i+2*k] - a[i-1]);
  }
  print(ans);

  return 0;
}