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
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << " ";
    os << *it;
  }
  return os;
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
#define dump(...) cout<<#__VA_ARGS__<<": [L_"<<__LINE__<<"]"<<'\n'; print(__VA_ARGS__);cout<<'\n';

template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }


int main() {
  int h, w, k; cin>>h>>w>>k;
  vector<string> s(h);
  rep(i, h) cin>>s[i];
  vector<vector<int>> ans(h, vector<int>(w, 0));

  int t = 1;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') {
      ans[i][j] = t;
      ++t;
    }
  }
  rep(i, h) {
    int tt = 0;
    rep(j, w) {
      if (ans[i][j] != 0) tt = ans[i][j];
      if (ans[i][j] == 0) ans[i][j] = tt;
    }
  }
  rep(i, h) {
    int tt = 0;
    RREP(j, w, 0) {
      if (ans[i][j] != 0) tt = ans[i][j];
      if (ans[i][j] == 0) ans[i][j] = tt;
    }
  }
  rep(j, w) {
    REP(i, 1, h) {
      if (ans[i][j] == 0) ans[i][j] = ans[i-1][j];
    }
  }
  rep(j, w) {
    RREP(i, h-1, 0) {
      if (ans[i][j] == 0) ans[i][j] = ans[i+1][j];
    }
  }
  rep(i, h) {
    print(ans[i]);
  }

  return 0;
}