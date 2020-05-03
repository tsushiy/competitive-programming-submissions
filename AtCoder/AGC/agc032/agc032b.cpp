#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  vector<pair<int, int>> ans;

  for (int i = 1; i <= n; i++) {
    int x = (n%2 == 0) ? (n + 1 - i) : n - i;
    for (int j = i+1; j <= n; j++) {
      if (j != x) {
        ans.emplace_back(make_pair(i, j));
      }
    }
  }

  cout << ans.size() << endl;
  for (auto x: ans) {
    cout << x.first << ' ' << x.second << endl;
  }

  return 0;
}