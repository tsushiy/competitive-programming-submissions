#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  string s; cin>>s;
  int k; cin>>k;
  if (s == string(s.size(), '1')) {
    print('1');
    return 0;
  }
  rep(i, s.size()) {
    if (i+1 == k) {
      print(s[i]);
      return 0;
    }
    if (s[i] != '1') {
      print(s[i]);
      return 0;
    }
  }

  return 0;
}