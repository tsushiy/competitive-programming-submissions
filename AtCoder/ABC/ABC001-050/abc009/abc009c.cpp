#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int diff(string s, string t) {
  vector<int> a(26, 0), b(26, 0);
  rep(i, s.size()) ++a[s[i]-'a'];
  rep(i, t.size()) ++b[t[i]-'a'];
  int ret = 0;
  rep(i, 26) ret += abs(a[i]-b[i]);
  return ret/2;
}

int main() {
  int n, k; cin>>n>>k;
  string s; cin>>s;
  string t = s;

  int d = 0;
  rep(i, n) {
    int dt = 0;
    REP(j, i+1, n) {
      string ss = t;
      if (ss[i] > ss[j]) {
        swap(ss[i], ss[j]);
        int dtt = (s[i] != ss[i]) + diff(s.substr(i+1, 110), ss.substr(i+1, 110));
        if (d + dtt <= k) {
          dt = dtt;
          swap(t[i], t[j]);
        }
      }
    }
    d += (s[i]!=t[i]);
  }
  print(t);

  return 0;
}