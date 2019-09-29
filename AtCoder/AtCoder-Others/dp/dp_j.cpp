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

int n;
double dp[310][310][310] = {};

double rec(int x, int y, int z) {
  if (x==0 and y==0 and z==0) return 0;
  if (dp[x][y][z] != 0) return dp[x][y][z];

  double ret = 1.0;
  if(x) ret += rec(x-1, y, z) * x / n;
  if(y) ret += rec(x+1, y-1, z) * y / n;
  if(z) ret += rec(x, y+1, z-1) * z / n;
  return dp[x][y][z] = ret * n / (x+y+z);
}

int main() {
  cin>>n;
  int x=0, y=0, z=0;
  rep(i, n){
    int a; cin>>a;
    if (a==1) ++x;
    if (a==2) ++y;
    if (a==3) ++z;
  }
  rec(x, y, z);
  cout<<fixed<<setprecision(10);
  print(dp[x][y][z]);

  return 0;
}
