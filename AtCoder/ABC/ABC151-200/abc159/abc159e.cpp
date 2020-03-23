#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

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

int popcount(int a) {
  int ret = 0;
  rep(i, 10) if (a & (1<<i)) ++ret;
  return ret;
}

int main() {
  int h, w, K; cin>>h>>w>>K;
  vector<string> s(h);
  rep(i, h) cin>>s[i];
  int ans = (h-1)+(w-1);

  rep(i, (1<<(h-1))) {
    int curans = popcount(i);
    vector<int> tmp(10, 0);
    bool good = true;
    rep(j, w) {
      int pos = 0;
      bool recalc = false;
      rep(k, h) {
        tmp[pos] += s[k][j] == '1';
        if (tmp[pos] > K) {
          recalc = true;
          ++curans;
          break;
        }
        if (k != h-1 and (i & (1<<k))) ++pos;
      }
      if (recalc) {
        pos = 0;
        rep(k, 10) tmp[k] = 0;
        rep(k, h) {
          tmp[pos] += s[k][j] == '1';
          if (tmp[pos] > K) good = false;
          if (k != h-1 and (i & (1<<k))) ++pos;
        }
      }
    }
    if (good) ans = min(ans, curans);
  }
  print(ans);

  return 0;
}