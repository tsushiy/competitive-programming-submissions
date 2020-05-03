#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t; cin>>n>>t;
  vector<long long> a(n);
  int ans = 0;
  for (int i = 0; i < n; i++) cin>>a[i];

  long long ma = 0, diff = 0;
  for (int i = n-1; i >= 0; i--) {
    ma = max(ma, a[i]);
    diff = max(diff, ma - a[i]);
  }

  ma = 0;
  for (int i = n-1; i >= 0; i--) {
    ma = max(ma, a[i]);
    if (ma - a[i] == diff) ++ans;
  }

  cout << ans << endl;

  return 0;
}