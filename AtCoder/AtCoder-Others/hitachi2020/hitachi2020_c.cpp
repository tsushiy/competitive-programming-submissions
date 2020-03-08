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
  os << "";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << " ";
    os << *it;
  }
  return os << "";
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

int bi[200000];
bool visited[200000];

void dfs(vector<vector<int>> &graph, int x, bool c) {
  visited[x] = true;
  bi[x] = c;
  for (auto nx: graph[x]) {
    if (visited[nx]) continue;
    dfs(graph, nx, !c);
  }
}

int main() {
  int n; cin>>n;
  vector<vector<int>> graph(n);
  rep(i, n-1) {
    int a, b; cin>>a>>b;
    --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  dfs(graph, 0, false);

  int one = 0, two = 0;
  vector<int> ans(n);
  rep(i, n) {
    ++bi[i];
    if (bi[i] == 1) ++one;
    else ++two;
  }

  int alt;
  if (one < (n / 3 + (n % 3 > 0))) {
    alt = 1;
    rep(i, n) if (bi[i] == 1) bi[i] = 0;
  } else if (two < (n / 3 + (n % 3 == 2))) {
    alt = 2;
    rep(i, n) if (bi[i] == 2) bi[i] = 0;
  } else alt = 0;

  vector<int> count(3, 0);
  count[0] = 1;
  rep(i, n) {
    int t = bi[i];
    int x = count[t] * 3 + t;
    if (x > n) {
      int y = count[alt] * 3 + alt;
      if (y > n) {
        ans[i] = count[0] * 3;
        ++count[0];
      } else {
        ans[i] = y;
        ++count[alt];
      }
    } else {
      ans[i] = x;
      ++count[t];
    }
  }
  print(ans);

  return 0;
}