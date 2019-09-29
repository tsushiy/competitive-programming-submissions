#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

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

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n; cin>>n;
  vector<deque<int>> a(n);
  vector<int> ans;
  rep(i, n) {
    int p; cin>>p;
    rep(j, p) {
      int t; cin>>t;
      a[i].push_back(t);
    }
  }
  bool flag = true;
  while (flag) {;
    flag = false;
    rep(i, n) {
      if (!a[i].empty()) {
        ans.push_back(a[i].front());
        a[i].pop_front();
        flag = true;
      }
    }
  }
  for (vector<int>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
    cout<<*it;
    if (it != ans.end()-1) cout<<" ";
    else cout<<'\n';
  }
  return 0;
}
