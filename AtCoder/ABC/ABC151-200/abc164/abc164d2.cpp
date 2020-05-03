#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 2019;

int main() {
  string s; cin>>s;
  vector<long long> v(2020, 0);
  v[0] = 1;

  int cur = 0, p = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    cur = (cur + (s[i] - '0') * p) % MOD;
    p = (p * 10) % MOD;
    ++v[cur];
  }

  long long ans = 0;
  for (int i = 0; i < 2020; i++) {
    ans += v[i] * (v[i] - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}