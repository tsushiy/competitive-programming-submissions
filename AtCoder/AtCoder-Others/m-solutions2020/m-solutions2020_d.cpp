#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  int n; cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];

  long long cur = 1000;
  rep(i, n-1) {
    if (a[i] < a[i+1]) {
      long long stock = cur / a[i];
      cur -= (a[i] * stock);
      cur += (a[i+1] * stock);
    }
  }
  print(cur);

  return 0;
}