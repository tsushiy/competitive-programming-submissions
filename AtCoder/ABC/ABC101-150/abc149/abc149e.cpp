#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr long long LLINF = 1LL << 62;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  long long n, m; cin>>n>>m;
  vector<long long> a(n);
  rep(i, n) cin>>a[i];
  sort(a.begin(), a.end());

  vector<long long> acc(n+1, 0);
  rep(i, n) acc[i+1] = a[i] + acc[i];

  long long ok = 0, ng = LLINF;
  while (ok + 1 < ng) {
    long long mid = (ok + ng) / 2;
    long long cnt = 0;
    rep(i, n) {
      cnt += a.end() - lower_bound(a.begin(), a.end(), mid - a[i]);
    }
    if (cnt < m) ng = mid;
    else ok = mid;
  }

  long long ans = 0;
  long long cnt = 0;
  rep(i, n) {
    int idx = lower_bound(a.begin(), a.end(), ok - a[i]) - a.begin();
    cnt += n - idx;
    if (idx < n) ans += a[i] * (n-idx) + (acc[n] - acc[idx]);
  }
  if (cnt > m) ans -= ok * (cnt - m);
  print(ans);

  return 0;
}