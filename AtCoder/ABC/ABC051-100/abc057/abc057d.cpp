#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;

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

template<unsigned int N = 50>
struct Comb {
  long long c[N+1][N+1];

  constexpr Comb() noexcept : c() {
    for (size_t i = 0; i <= N; ++i) {
      for (size_t j = 0; j <= N; ++j) {
        if (j == 0 or j == i) c[i][j] = 1LL;
        else c[i][j] = c[i-1][j-1] + c[i-1][j];
      }
    }
  }
  constexpr long long comb(unsigned int n, unsigned int k) const noexcept {
    return c[n][k];
  }
};

int main() {
  int n, a, b; cin>>n>>a>>b;
  vector<long long> v(n);
  rep(i, n) cin>>v[i];
  sort(v.begin(), v.end(), greater<long long>());

  double ans = 0;
  rep(i, a) ans += v[i];
  cout<<fixed<<setprecision(10)<<ans/a<<endl;

  Comb<> mc;
  long long cnt = 0;
  int total = 0;
  rep(i, n) if (v[i] == v[a-1]) ++total;
  if (v[0] == v[a-1]) {
    int tmp = -1;
    REP(j, a, b+1) {
      int inner = 0;
      rep(i, n) if (v[i] == v[a-1] and i < j) ++inner;
      if (tmp != inner) {
        tmp = inner;
        cnt += mc.comb(total, inner);
      }
    }
  } else {
    int inner = 0;
    rep(i, n) if (v[i] == v[a-1] and i < a) ++inner; 
    cnt += mc.comb(total, inner);
  }
  print(cnt);

  return 0;
}
