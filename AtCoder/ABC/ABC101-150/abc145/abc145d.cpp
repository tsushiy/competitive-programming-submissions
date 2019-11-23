#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;
constexpr double EPS = 1e-9;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pa) {
  return os << "(" << pa.first << ", " << pa.second << ")";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &se) {
  os << "{";
  for (auto it = se.begin(); it != se.end(); ++it) {
    if (it != se.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &ma) {
  os << "{";
  for (auto it = ma.begin(); it != ma.end(); ++it) {
    if (it != ma.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "}";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }
#define dump(...) cout<<#__VA_ARGS__<<": [L_"<<__LINE__<<"]"<<'\n'; print(__VA_ARGS__);cout<<'\n';

template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }

struct RuntimeModComb {
private:
  unsigned int N;
  long long MOD;

public:
  vector<long long> fac;
  vector<long long> inv;
  vector<long long> ifac;

  RuntimeModComb(unsigned int N, long long MOD) : N(N), MOD(MOD), fac(), inv(), ifac() {
    fac.resize(N), inv.resize(N), ifac.resize(N);
    fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
    for (size_t i = 2; i <= N; ++i) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      ifac[i] = ifac[i-1] * inv[i] % MOD;
    }
  }
  long long comb(unsigned int n, unsigned int k) const {
    if (n < 0 || k < 0 || k > n) return 0;
    return (fac[n] * ifac[k] % MOD) * ifac[n-k] % MOD;
  }
};

int main() {
  int x, y; cin>>x>>y;
  int d = x+y;
  if (d%3 != 0) {
    print(0);
    return 0;
  }
  int n = (x+y)/3;
  RuntimeModComb mc(1000010, MOD);
  int basex = 2*n, basey = n;
  int m = -1;
  rep(i, n+1) {
    if (basex==x and basey == y) {
      m = i;
      break;
    }
    basex -= 1;
    basey += 1;
  }
  if (m == -1) {
    print(0);
    return 0;
  }
  long long ans = mc.comb(n, m);
  print(ans);

  return 0;
}
