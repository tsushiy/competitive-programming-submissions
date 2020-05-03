#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, n; cin>>a>>b>>n;
  long long x = min(b-1, n);
  long long ans = a * x / b - a * (x / b);

  cout << ans << endl;

  return 0;
}