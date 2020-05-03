#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;

  int x = -1;
  for (int i = 1; i * (i+1) / 2 <= n; i++) {
    if ((i * (i+1)) / 2 == n) x = i;
  }
  if (x == -1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  cout << x + 1 << endl;

  vector<vector<int>> ans;
  vector<int> pos;
  int last = 1;

  for (int i = 0; i < x + 1; i++) {
    vector<int> tmp;
    for (int j = 0; j < i; j++) if (pos[j] < x) {
      tmp.emplace_back(ans[j][pos[j]]);
      ++pos[j];
    }
    int m = tmp.size();
    pos.emplace_back(m);
    while (m < x) {
      tmp.emplace_back(last);
      ++last;
      ++m;
    }
    ans.emplace_back(tmp);
  }

  for (int i = 0; i < x + 1; i++) {
    cout << x;
    for (int j = 0; j < x; j++) {
      cout << ' ' << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}