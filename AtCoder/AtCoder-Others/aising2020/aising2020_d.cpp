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

template<typename Tuple, size_t N>
struct TuplePrinter {
  static void print(const Tuple &t) {
    TuplePrinter<Tuple, N-1>::print(t);
    cout << ", " << get<N-1>(t);
  }
};

template<typename Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(const Tuple &t) {
    cout << get<0>(t);
  }
};

template<typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tup) {
  os << "(";
  TuplePrinter<decltype(tup), sizeof...(T)>::print(tup);
  return os << ")";
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

vector<long long> cnt(200010, 0);

int rec(int x) {
  if (cnt[x] != 0) return cnt[x];
  int cnt = __builtin_popcount(x);
  if (cnt == 0) return 0;
  int r = x % cnt;
  return rec(r) + 1;
}

int main() {
  int n ; cin>>n;
  string x; cin>>x;

  int popcnt = 0;
  rep(i, n) if (x[i] == '1') popcnt += 1;
  // print(popcnt);

  REP(i, 1, 200010) cnt[i] = rec(i);

  long long remm = 0, remp = 0;
  rep(i, n) {
    if (x[i] == '1') {
      if (popcnt > 1) {
        remm += modpow(2, n-i-1, popcnt - 1);
        remm %= (popcnt - 1);
      }
      remp += modpow(2, n-i-1, popcnt + 1);
      remp %= popcnt + 1;
    }
  }
  // print(remm, remp);

  rep(i, n) {
    if (x[i] == '1') {
      if (popcnt == 1) {
        print(0);
        continue;
      }
      long long rem = remm - modpow(2, n-i-1, popcnt - 1);
      if (rem < 0) rem += (popcnt - 1);
      rem %= (popcnt - 1);
      // print("mr", rem);
      if (rem == 0) print(1);
      else {
        print(cnt[rem] + 1);
      }
    } else {
      long long rem = remp + modpow(2, n-i-1, popcnt + 1);
      rem %= (popcnt + 1);
      // print("pr", rem);
      if (rem == 0) print(1);
      else {
        print(cnt[rem] + 1);
      }
    }
  }

  return 0;
}