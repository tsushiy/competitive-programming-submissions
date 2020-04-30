#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin>>n;
  long long ans = 0;

  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  for (long long i = 10; i <= 1e18; i *= 5) {
    long long x = n / i;
    ans += x;
  }

  cout << ans << endl;

  return 0;
}