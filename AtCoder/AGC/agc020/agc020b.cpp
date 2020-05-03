#include <bits/stdc++.h>
using namespace std;

int main() {
  int k; cin>>k;
  vector<long long> a(k);
  for (int i = 0; i < k; i++) cin>>a[i];

  long long ma = 2, mi = 2;
  for (int i = k-1; i >= 0; i--) {
    long long d = a[i] - mi % a[i];
    if (d != a[i] and mi + d > ma) {
      cout << -1 << endl;
      return 0;
    }
    mi = mi % a[i] == 0 ? mi / a[i] * a[i] : (mi / a[i] + 1) * a[i];
    ma = ma / a[i] * a[i] + a[i] - 1;
  }

  cout << mi << ' ' << ma << endl;

  return 0;
}