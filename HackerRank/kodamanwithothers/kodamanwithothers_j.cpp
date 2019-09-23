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
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<", "; print(y...); }
#define dump(...) cout<<#__VA_ARGS__<<": [L_"<<__LINE__<<"]"<<'\n'; print(__VA_ARGS__);cout<<'\n';

template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }

struct Interval {
  int s, t, weight;
  Interval(int s, int t, int weight) : s(s), t(t), weight(weight) {}
  bool operator<(const Interval & rhs) const {
    if (t != rhs.t) return t < rhs.t;
    if (s != rhs.s) return s < rhs.s;
    return weight < rhs.weight;
  }
};

long long scheduling(vector<Interval> &intervals) {
  sort(intervals.begin(), intervals.end());
  vector<long long> dp(intervals.size(), 0);
  vector<int> buf;
  for (int i = 0; i < (int)intervals.size(); ++i) {
    int prev = lower_bound(buf.begin(), buf.end(), intervals[i].s) - buf.begin();
    --prev;
    dp[i] = max((i ? dp[i-1] : 0), intervals[i].weight + ((prev == -1) ? 0 : dp[prev]));
    buf.push_back(intervals[i].t);
  }
  return dp[intervals.size()-1];
}

int main() {
  int n; cin>>n;
  vector<Interval> intervals;
  rep(i, n) {
    int a, b, c; cin>>a>>b>>c;
    intervals.emplace_back(a, b-1, c);
  }
  print(scheduling(intervals));
  return 0;
}
