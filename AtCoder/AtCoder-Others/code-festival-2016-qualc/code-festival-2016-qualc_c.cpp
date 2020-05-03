#include <bits/stdc++.h>
using namespace std;

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

int main() {
  int n; cin>>n;
  vector<long long> t(n), a(n);
  for (int i = 0; i < n; i++) cin>>t[i];
  for (int i = 0; i < n; i++) cin>>a[i];

  vector<long long> ma(n, 1e9), mi(n, 1);
  ma[0] = mi[0] = t[0];
  for (int i = 1; i < n; i++) {
    if (t[i] != t[i-1]) {
      ma[i] = mi[i] = t[i];
    } else {
      ma[i] = t[i];
    }
  }
  if (not (mi[n-1] <= a[n-1] and a[n-1] <= ma[n-1])) {
    cout << 0 << endl;
    return 0;
  }
  ma[n-1] = mi[n-1] = a[n-1];
  for (int i = n-2; i >= 0; i--) {
    if (a[i] != a[i+1]) {
      if (not (mi[i] <= a[i] and a[i] <= ma[i])) {
        cout << 0 << endl;
        return 0;
      }
      ma[i] = mi[i] = a[i];
    } else {
      ma[i] = min(ma[i], a[i]);
    }
  }

  Mint<> ans = 1;
  for (int i = 0; i < n; i++) {
    int d = ma[i] - mi[i] + 1;
    if (d <= 0) {
      cout << 0 << endl;
      return 0;
    }
    ans *= d;
  }

  cout << ans << endl;

  return 0;
}