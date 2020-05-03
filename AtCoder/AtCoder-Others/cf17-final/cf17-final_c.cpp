#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin>>d[i];
  sort(d.begin(), d.end());

  vector<int> v(25, 0);
  v[0] = 1;
  bool pos = true;
  for (int i = 0; i < n; i++) {
    if (pos) ++v[d[i]];
    else ++v[24-d[i]];
    pos = !pos;
  }
  v[0] += v[24];

  int ans = 12, cnt = 12;
  for (int i = 0; i < 24; i++) {
    if (v[i] >= 2) ans = 0;
    else if (v[i] == 1) {
      ans = min(ans, cnt);
      cnt = 1;
    }
    else ++cnt;
  }
  ans = min(ans, cnt);

  cout << ans << endl;

  return 0;
}