#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

inline bool is_prime(long long x) {
  if (x <= 1) return false;
  for (long long i = 2; i*i <= x; ++i) if (x % i == 0) return false;
  return true;
}

bool table[100010] = {};
int acc[100010] = {};

void calc() {
  for (int i = 1; i < 100010; i += 2) {
    if (is_prime(i) and is_prime((i+1)/2)) table[i] = true;
  }
  rep(i, 100000) acc[i+1] = acc[i] + table[i+1];
}

int main() {
  int q; cin>>q;
  calc();
  rep(i, q) {
    int l, r; cin>>l>>r;
    print(acc[r] - acc[l-1]);
  }
  return 0;
}
