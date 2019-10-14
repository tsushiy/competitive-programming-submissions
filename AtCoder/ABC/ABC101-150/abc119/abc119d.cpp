#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr long long LLINF = 1LL << 60;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int a, b, q; cin>>a>>b>>q;
  vector<long long> s(a+2), t(b+2);
  s[0] = t[0] = -LLINF;
  s[a+1] = t[b+1] = LLINF;
  rep(i, a) cin>>s[i+1];
  rep(i, b) cin>>t[i+1];

  rep(i, q) {
    long long x; cin>>x;
    long long ans = LLINF;
    long long sr = *lower_bound(s.begin(), s.end(), x);
    long long sl = *(lower_bound(s.begin(), s.end(), x) - 1);
    long long tr = *lower_bound(t.begin(), t.end(), x);
    long long tl = *(lower_bound(t.begin(), t.end(), x) - 1);

    if (sr <= tr) ans = min(ans, tr-x);
    else ans = min(ans, sr-x);
    if (sl <= tl) ans = min(ans, x-sl);
    else ans = min(ans, x-tl);
    ans = min(ans, (tr-x) + (x-sl) + min((tr-x), (x-sl)));
    ans = min(ans, (sr-x) + (x-tl) + min((sr-x), (x-tl)));
    print(ans);
  }

  return 0;
}