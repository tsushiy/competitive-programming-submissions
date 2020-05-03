#include <bits/stdc++.h>
using namespace std;

int main() {
  string a; cin>>a;
  int n = a.size();

  vector<int> s(26, 0);
  for (int i = 0; i < n; i++) ++s[a[i] - 'a'];

  long long ans = 0;
  for (int i = 0; i < 26; i++) ans += (long long)s[i] * (n-s[i]);
  ans = ans / 2 + 1;
  cout << ans << endl;

  return 0;
}