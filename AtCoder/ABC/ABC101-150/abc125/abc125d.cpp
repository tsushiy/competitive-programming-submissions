#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;++i)
template<class T, class U>inline bool chmax(T &a, U const &b) { if(a<b){ a=b;return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, U const &b) { if(b<a){ a=b;return 1; } return 0; }
const int inf = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }

  long long ans = 0;
  int neg = 0, min = inf;
  rep(i, n) {
    if (a[i] < 0) {
      ++neg;
      a[i] *= -1;
    }
    ans += a[i];
    chmin(min, a[i]);
  }

  if (neg % 2) {
    cout << ans - min * 2 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}