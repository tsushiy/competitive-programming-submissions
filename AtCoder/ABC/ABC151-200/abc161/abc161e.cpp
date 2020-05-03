#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, c; cin>>n>>k>>c;
  string s; cin>>s;

  vector<int> l(k, 0), r(k, 0);
  int cur = 0, d = 1e9;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o' and d >= c and cur < k) {
      l[cur++] = i;
      d = 0;
    } else {
      ++d;
    }
  }
  cur = k-1, d = 1e9;
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == 'o' and d >= c and cur >= 0) {
      r[cur--] = i;
      d = 0;
    } else {
      ++d;
    }
  }

  for (int i = 0; i < k; i++) {
    if (l[i] == r[i]) {
      cout << l[i]+1 << endl;
    }
  }

  return 0;
}