#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

long long modpow(long long x, long long n, long long mod = 1000000007) {
  if (n < 0) return 0;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  string s; cin>>s;
  int n = s.size();

  vector<long long> a(n), c(n), l(n), r(n);
  for (int i = 0, cnt = 0; i < n; ++i) {
    a[i] = cnt;
    if (s[i] == 'A') ++cnt;
  }
  for (int i = 0, cnt = 0; i < n; ++i) {
    l[i] = cnt;
    if (s[i] == '?') ++cnt;
  }
  for (int i = n-1, cnt = 0; i >= 0; --i) {
    c[i] = cnt;
    if (s[i] == 'C') ++cnt;
  }
  for (int i = n-1, cnt = 0; i >= 0; --i) {
    r[i] = cnt;
    if (s[i] == '?') ++cnt;
  }

  long long ans = 0;
  rep(i, n) if (s[i] == 'B' or s[i] == '?') {
    ans = (ans + a[i]*c[i]*modpow(3, l[i]+r[i])) % MOD;
    ans = (ans + l[i]*c[i]*modpow(3, l[i]+r[i]-1)) % MOD;
    ans = (ans + a[i]*r[i]*modpow(3, l[i]+r[i]-1)) % MOD;
    ans = (ans + l[i]*r[i]*modpow(3, l[i]+r[i]-2)) % MOD;
  }
  print(ans);

  return 0;
}