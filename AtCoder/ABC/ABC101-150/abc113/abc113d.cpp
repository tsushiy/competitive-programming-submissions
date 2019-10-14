#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

template<long long MOD = 1000000007>
struct Mint {
private:
  long long val;

public:
  constexpr Mint(const long long x = 0) noexcept : val(x < 0 ? x % MOD + MOD : x >= MOD ? x % MOD : x) {}
  constexpr Mint &operator+=(const Mint rhs) noexcept {
    if ((val += rhs.val) >= MOD) val -= MOD;
    return *this;
  }
  constexpr Mint &operator-=(const Mint rhs) noexcept {
    if ((val -= rhs.val) < 0) val += MOD;
    return *this;
  }
  constexpr Mint &operator*=(const Mint rhs) noexcept {
    val = val * rhs.val % MOD;
    return *this;
  }
  constexpr Mint &operator/=(Mint rhs) noexcept {
    val = val * rhs.inv().val % MOD;
    return *this;
  }
  constexpr Mint operator+(const Mint& rhs) const noexcept { return Mint(*this) += rhs; }
  constexpr Mint operator-(const Mint& rhs) const noexcept { return Mint(*this) -= rhs; }
  constexpr Mint operator*(const Mint& rhs) const noexcept { return Mint(*this) *= rhs; }
  constexpr Mint operator/(const Mint& rhs) const noexcept { return Mint(*this) /= rhs; }
  constexpr Mint inv() const noexcept { return pow(MOD-2); }
  constexpr Mint pow(long long n) const noexcept {
    Mint ret(1), mul(val);
    while (n) {
      if (n % 2) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  constexpr bool operator==(const Mint& rhs) const noexcept { return val == rhs.val; }
  constexpr bool operator!=(const Mint& rhs) const noexcept { return val != rhs.val; }
  friend ostream &operator<<(ostream &os, const Mint<MOD> &x) { return os << x.val; }
  friend istream &operator>>(istream &is, Mint<MOD> &x) {
    long long t;
    is >> t;
    x.val = t % MOD;
    return is;
  }
};

int h, w, k;

bool check(int x) {
  bool ret = true;
  rep(i, w-2) {
    if (x & (1<<i) && x & (1<<(i+1))) ret = false;
  }
  return ret;
}

int main() {
  cin>>h>>w>>k;
  if (w==1) {
    print(1);
    return 0;
  }
  Mint<> dp[110][10] = {};
  dp[0][0] = 1;
  rep(i, h) {
    rep(j, 1<<(w-1)) {
      if (!check(j)) continue;
      rep(k, w-1) {
        if (j & 1<<k) {
          dp[i+1][k] += dp[i][k+1];
          dp[i+1][k+1] += dp[i][k];
        }
      }
      if (!(j & 1<<0)) dp[i+1][0] += dp[i][0];
      if (!(j & 1<<(w-2))) dp[i+1][w-1] += dp[i][w-1];
      rep(k, w-2) {
        if (!(j & (1<<k)) && !(j & (1<<(k+1)))) {
          dp[i+1][k+1] += dp[i][k+1];
        }
      }
    }
  }
  print(dp[h][k-1]);

  return 0;
}