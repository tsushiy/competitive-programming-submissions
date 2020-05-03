#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n; cin>>h>>w>>n;
  int sr, sc; cin>>sr>>sc;
  string s, t; cin>>s>>t;

  int l = 0, r = 0, u = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') ++l;
    if (s[i] == 'R') ++r;
    if (s[i] == 'U') ++u;
    if (s[i] == 'D') ++d;
    if (sc - l <= 0 or sc + r > w or sr - u <= 0 or sr + d > h) {
      cout << "NO" << endl;
      return 0;
    }
    if (t[i] == 'R' and sc - (l - 1) <= w) --l;
    if (t[i] == 'L' and sc + (r - 1) > 0) --r;
    if (t[i] == 'D' and sr - (u - 1) <= h) --u;
    if (t[i] == 'U' and sr + (d - 1) > 0) --d;
  }
  cout << "YES" << endl;

  return 0;
}