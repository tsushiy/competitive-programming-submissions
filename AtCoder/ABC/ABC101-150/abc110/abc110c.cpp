#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  string s, t; cin>>s>>t;
  if (s.size() != t.size()) {
    print("No");
    return 0;
  }

  vector<set<int>> ss(30), ts(30);
  rep(i, s.size()){
    ss[s[i]-'a'].emplace(t[i]-'a');
    ts[t[i]-'a'].emplace(s[i]-'a');
  }
  rep(i, 30) if (ss[i].size() > 1 or ts[i].size() > 1) {
    print("No");
    return 0;
  }
  print("Yes");

  return 0;
}