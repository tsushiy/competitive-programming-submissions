#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin>>n>>k;
  vector<long long> a(n), s(n+1, 0);
  for (int i = 0; i < n; i++) cin>>a[i];
  for (int i = 0; i < n; i++) s[i+1] = s[i] + a[i];

  long long ans = 0;
  map<int, int> v;
  int l = 0;
  for (int r = 0; r < n+1; r++) {
    if (r-l >= k) {
      --v[(s[l]-l)%k];
      ++l;
    }
    ans += v[(s[r]-r)%k];
    ++v[(s[r]-r)%k];
  }
  cout << ans << endl;

  return 0;
}