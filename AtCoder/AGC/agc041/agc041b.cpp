#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n; cin>>n;
  long long m, v, p; cin>>m>>v>>p;
  vector<long long> a(n);
  rep(i, n) cin>>a[i];
  sort(a.begin(), a.end());

  int ng = -1, ok = n;
  while (ng + 1 < ok) {
    int mid = (ng + ok) / 2;
    bool good = true;
    int x = a[mid] + m;

    int large_idx = lower_bound(a.begin(), a.end(), x+1) - a.begin();
    int large = n - large_idx;
    if (large >= p) good = false;

    int same_idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    int rem_prob = p - (n - same_idx + 1);
    long long rem_vote = m * (v - 1 - large);
    int same = large_idx - same_idx;
    rep(i, same) {
      if (large + i + 1 >= p) break;
      if (rem_prob > 0) {
        rem_vote -= m;
        --rem_prob;
      }
    }
    RREP(i, same_idx, 0) {
      if (i == mid) continue;
      if (rem_prob > 0) {
        rem_vote -= m;
        --rem_prob;
      } else {
        rem_vote -= min(m, x - a[i]);
      }
    }
    if (rem_vote > 0) good = false;

    if (good) ok = mid;
    else ng = mid;
  }

  print(n - ok);

  return 0;
}