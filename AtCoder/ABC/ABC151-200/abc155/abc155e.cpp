#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin>>s;
  s = '0' + s;
  int n = s.size();

  // 0でちょうど払う、1で1多く払う
  vector<vector<int>> dp(n, vector<int>(2, 1e9));
  dp[0][0] = 0;
  dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    dp[i][0] = min(dp[i-1][0] + (s[i] - '0'), dp[i-1][1] + (10 - (s[i] - '0')));
    dp[i][1] = min(dp[i-1][0] + (s[i] - '0' + 1), dp[i-1][1] + (10 - (s[i] - '0') - 1));
  }
  cout << dp[n-1][0] << endl;

  return 0;
}