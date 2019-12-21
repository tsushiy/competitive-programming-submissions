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
  int h, w; cin>>h>>w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<int>> b(h, vector<int>(w));
  rep(i, h) rep(j, w) cin>>a[i][j];
  rep(i, h) rep(j, w) cin>>b[i][j];

  vector<vector<vector<int>>> c(h, vector<vector<int>>(w, vector<int>(20000, 0)));
  c[0][0][abs(a[0][0] - b[0][0])] = 1;

  REP(i, 1, w) {
    rep(j, 20000) if (c[0][i-1][j] == 1) {
      int t = abs(a[0][i] - b[0][i]);
      int t1 = abs(j - t);
      if (t1 < 20000) c[0][i][t1] = 1;
      int t2 = j + t;
      if (t2 < 20000) c[0][i][t2] = 1;
    }
  }

  REP(k, 1, h) {
    rep(j, 20000) if (c[k-1][0][j] == 1) {
      int t = abs(a[k][0] - b[k][0]);
      int t1 = abs(j - t);
      if (t1 < 20000) c[k][0][t1] = 1;
      int t2 = j + t;
      if (t2 < 20000) c[k][0][t2] = 1;
    }
  }

  REP(i, 1, w) {
    REP(k, 1, h) {
      rep(j, 20000) if (c[k][i-1][j] == 1) {
        int t = abs(a[k][i] - b[k][i]);
        int t1 = abs(j - t);
        if (t1 < 20000) c[k][i][t1] = 1;
        int t2 = j + t;
        if (t2 < 20000) c[k][i][t2] = 1;
      }
      rep(j, 20000) if (c[k-1][i][j] == 1) {
        int t = abs(a[k][i] - b[k][i]);
        int t1 = abs(j - t);
        if (t1 < 20000) c[k][i][t1] = 1;
        int t2 = j + t;
        if (t2 < 20000) c[k][i][t2] = 1;
      }
    }
  }

  rep(i, 20000) {
    if (c[h-1][w-1][i] == 1) {
      print(i);
      return 0;
    }
  }

  return 0;
}