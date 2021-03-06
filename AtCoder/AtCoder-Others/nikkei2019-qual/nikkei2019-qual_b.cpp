#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

struct custom_tf : std::numpunct<char> {
  std::string do_truename() const { return "Yes"; }
  std::string do_falsename() const { return "No"; }
};

struct Initializer {
  Initializer() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cout << std::fixed << std::setprecision(15) << std::boolalpha;
    std::cout.imbue(std::locale(std::cout.getloc(), new custom_tf));
  }
} initializer;

template<typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &pa) {
  return os << "(" << pa.first << ", " << pa.second << ")";
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &se) {
  os << "{";
  for (auto it = se.begin(); it != se.end(); ++it) {
    if (it != se.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::map<T, U> &ma) {
  os << "{";
  for (auto it = ma.begin(); it != ma.end(); ++it) {
    if (it != ma.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "}";
}

inline void print(void) { std::cout<<'\n'; }
template<class T> inline void print(const T &x) { std::cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { std::cout<<x<<", "; print(y...); }
#define dump(...) std::cout<<#__VA_ARGS__<<": [L_"<<__LINE__<<"]"<<'\n'; print(__VA_ARGS__);std::cout<<'\n';

template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }


int main() {
  int n; cin>>n;
  string a, b, c;
  cin>>a>>b>>c;
  int ans = 0;
  rep(i, n) {
    if (a[i]!=b[i] and b[i]!=c[i] and a[i]!=c[i]) ans += 2;
    else if(a[i]==b[i] and b[i]==c[i]) ans += 0;
    else ans += 1;
  }
  print(ans);

  return 0;
}
