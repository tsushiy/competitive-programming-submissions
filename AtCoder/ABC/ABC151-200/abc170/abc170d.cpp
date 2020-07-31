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


int main() {
  int n; cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];
  sort(a.begin(), a.end());
  set<int> s(a.begin(), a.end());

  int ans = 0;
  rep(i, n) {
    if (i == 0 and n >= 2 and a[i] == a[i+1]) continue;
    if (i == n-1 and n >= 2 and a[i] == a[i-1]) continue;
    if (i != 0 and i != n-1 and (a[i] == a[i-1] or a[i] == a[i+1])) continue;

    bool ok = true;
    if (a[i] == 1) {
      ++ans;
      continue;
    }
    for (int j = 1; j * j <= a[i]; ++j) {
      if (j == 1) {
        if (s.find(j) != s.end()) {
          ok = false;
          break;
        } else continue;
      }
      if (a[i] % j == 0) {
        int rem = a[i] / j;
        if (s.find(j) != s.end() or s.find(rem) != s.end()) {
          ok = false;
          break;
        }
      }
    }
    if (ok) ++ans;
  }
  print(ans);

  return 0;
}