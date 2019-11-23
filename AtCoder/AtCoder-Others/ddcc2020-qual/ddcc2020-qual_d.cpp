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

vector<vector<pair<int, int>>> ha(10, vector<pair<int, int>>(10)); // (cnt, c)
pair<int, int> two(int a, int b) {
  int cnt = 0, c = 20;
  while (c >= 10) {
    c = a+b;
    a = c / 10;
    b = c % 10;
    ++cnt;
  }
  return make_pair(cnt, c);
}

long long naive(vector<int> v) {
  int sz = v.size();
  long long ret = 0;
  int a = v[0];
  REP(i, 1, sz) {
    int b = v[i];
    int cnt, c; tie(cnt, c) = ha[a][b];
    ret += cnt;
    a = c;
  }
  return ret;
}

pair<long long, int> f(int a, long long cnt) { // (cnt, c)
  long long ret = 0;
  long long t;
  int c;
  tie(t, c) = ha[a][a];
  ret = (cnt / 2) * t;
  return make_pair(ret, c);
}

int main() {
  rep(i, 10) rep(j, 10) {
    ha[i][j] = two(i, j);
  }

  int m; cin>>m;
  vector<int> d(m);
  vector<long long> c(m);
  rep(i, m) cin>>d[i]>>c[i];

  long long ans = 0;
  vector<int> v;
  rep(i, m) {
    int a = d[i];
    long long cnt = c[i];
    while (cnt != 0) {
      if (cnt % 2 == 1) {
        v.emplace_back(a);
        --cnt;
        if (cnt == 0) break;
      }
      long long t; int c;
      tie(t, c) = f(a, cnt);
      a = c;
      ans += t;
      cnt /= 2;
    }
  }
  ans += naive(v);
  print(ans);

  return 0;
}
