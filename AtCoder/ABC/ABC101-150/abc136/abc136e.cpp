#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a;

bool check(int x) {
  vector<int> rem(n);
  for (int i = 0; i < n; i++) rem[i] = a[i] % x;
  sort(rem.begin(), rem.end());

  int pos = 0, neg = 0;
  int r = n-1;
  for (int l = 0; l <= r; l++) {
    pos += rem[l];
    while (pos > neg) {
      neg += x - rem[r];
      --r;
    }
  }

  if (pos <= k) return true;
  else return false;
}

int main() {
  cin>>n>>k;
  a.resize(n);
  for (int i = 0; i < n; i++) cin>>a[i];

  int s;
  for (int i = 0; i < n; i++) s += a[i];
  vector<int> divs;
  for (int i = 1; i * i <= s; i++) {
    if (s % i == 0) {
      divs.emplace_back(i);
      divs.emplace_back(s / i);
    }
  }
  sort(divs.begin(), divs.end());

  int ans = 1;
  for (auto x: divs) {
    if (check(x)) ans = x;
  }
  cout << ans << endl;

  return 0;
}