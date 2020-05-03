#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p; cin>>n>>p;
  string s; cin>>s;
  vector<long long> v(p+1, 0);
  v[0] = 1;

  int cur = 0, e = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    cur = (cur + (s[i] - '0') * e) % p;
    e = (e * 10) % p;
    ++v[cur];
  }

  long long ans = 0;
  if (p == 2) {
    for (int i = 0; i < n; i++) {
      if ((s[i] - '0') % 2 == 0) ans += i+1;
    }
  } else if (p == 5) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '0' or s[i] == '5') ans += i+1;
    }
  } else {
    for (int i = 0; i < p+1; i++) {
      ans += v[i] * (v[i] - 1) / 2;
    }
  }
  cout << ans << endl;

  return 0;
}