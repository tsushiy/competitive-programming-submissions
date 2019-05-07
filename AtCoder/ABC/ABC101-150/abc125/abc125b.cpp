#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;++i)

int main() {
  int n;
  cin >> n;
  int ans = 0;
  vector<int> v(n), c(n);
  rep(i, n) { cin >> v[i]; }
  rep(i, n) { cin >> c[i]; }
  rep(i, n) {
    if (v[i] > c[i]) {
      ans += v[i] - c[i];
    }
  }
  cout << ans << endl;
  return 0;
}