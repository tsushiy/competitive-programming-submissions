#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;
constexpr double EPS = 1e-9;

struct custom_tf : numpunct<char> {
  string do_truename() const { return "Yes"; }
  string do_falsename() const { return "No"; }
};

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
    cout.imbue(locale(cout.getloc(), new custom_tf));
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

/**
 * @brief SegmentTree
 * @note construct : O(N)
 * @note query : O(logN)
 */
template<typename T, typename Monoid>
struct SegmentTree {
private:
  int n;
  vector<T> node;

public:
  constexpr SegmentTree(int n_) : node() {
    n = 1;
    while (n < n_) n <<= 1;
    node.resize(2*n-1, Monoid::unit());
    for (int i = 0; i < n_; ++i) node[i+n-1] = Monoid::unit();
    for (int i = n-2; i >= 0; --i) node[i] = Monoid::operate(node[2*i+1], node[2*i+2]);
  }
  void update(int i, T x) {
    node[i+n-1] = x;
    for (i = (i+n)/2; i > 0; i /= 2) {
      node[i-1] = Monoid::operate(node[2*i-1], node[2*i]);
    }
  }
  T get(int l, int r) const { // [l, r)
    assert(0 <= l and l <= r and r <= n);
    T lacc = Monoid::unit();
    T racc = Monoid::unit();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) lacc = Monoid::operate(lacc, node[(l++) - 1]);
      if (r % 2 == 1) racc = Monoid::operate(node[(--r) - 1], racc);
    }
    return Monoid::operate(lacc, racc);
  }
};

template<typename T>
struct MinMonoid {
  static constexpr T unit() { return make_pair(INF, -1); }
  static constexpr T operate(T a, T b) { return min(a, b); }
};

int main() {
  int n, q; cin>>n>>q;
  vector<int> a(n); cin>>a;

  using P = pair<int, int>;
  SegmentTree<P, MinMonoid<P>> sg(n);
  rep(i, n) sg.update(i, make_pair(a[i], i));

  rep(i, q) {
    int com, l, r; cin>>com>>l>>r;
    --l, --r;
    if (com==1) {
      swap(a[l], a[r]);
      sg.update(l, make_pair(a[l], l));
      sg.update(r, make_pair(a[r], r));
    } else {
      P p = sg.get(l, r+1);
      print(p.second+1);
    }
  }
}