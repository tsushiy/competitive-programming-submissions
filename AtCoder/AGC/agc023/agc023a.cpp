#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  vector<long long> a(n), acc(n);
  for (int i = 0; i < n; i++) cin>>a[i];

  acc[0] = a[0];
  for (int i = 1; i < n; i++) acc[i] = acc[i-1] + a[i];

  map<long long, int> ma;
  for (int i = 0; i < n; i++) ++ma[acc[i]];

  long long ans = 0;
  for (auto x: ma) {
    if (x.first == 0) ans += x.second;
    ans += (long long)x.second * (x.second - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}