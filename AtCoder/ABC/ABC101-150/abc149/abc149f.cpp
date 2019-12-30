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

int n;

int dfs(int par, int cur, vector<vector<int>> &graph, vector<vector<int>> &sub) {
  int sz = 1;
  for (auto nx: graph[cur]) {
    if (nx == par) continue;
    int t = dfs(cur, nx, graph, sub);
    sub[cur].emplace_back(t);
    sz += t;
  }
  if (sz != n) sub[cur].emplace_back(n - sz);
  return sz;
}

int main() {
  cin>>n;
  vector<vector<int>> graph(n), sub(n);
  rep(i, n-1) {
    int a, b; cin>>a>>b; --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  dfs(-1, 0, graph, sub);

  Mint<> ans = 0;
  rep(i, n) {
    int acc = 0;
    Mint<> t = 0;
    rep(j, sub[i].size()-1) {
      t += Mint<>(2).inv().pow(acc) *
           (Mint<>(1) - Mint<>(2).inv().pow(sub[i][j])) *
           Mint<>(2).inv() *
           (Mint<>(1) - Mint<>(2).inv().pow(n-1-acc-sub[i][j]));
      acc += sub[i][j];
    }
    ans += t;
  }
  print(ans);

  return 0;
}