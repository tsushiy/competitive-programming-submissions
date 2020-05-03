#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin>>n>>k;
  vector<long long> a(n), b, c;
  for (int i = 0; i < n; i++) cin>>a[i];
  for (int i = 0; i < n; i++) {
    long long cur = 0;
    for (int j = i; j < n; j++) {
      cur += a[j];
      b.emplace_back(cur);
    }
  }

  long long ans = 0;
  for (int i = 41; i >= 0; i--) {
    int cnt = 0;
    c.clear();
    for (int j = 0; j < b.size(); j++) {
      if (b[j] & (1LL<<i)) {
        ++cnt;
        c.emplace_back(b[j]);
      }
    }
    if (cnt >= k) {
      ans |= (1LL<<i);
      swap(b, c);
    }
  }

  cout << ans << endl;

  return 0;
}