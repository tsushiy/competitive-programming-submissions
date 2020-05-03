#include <bits/stdc++.h>
using namespace std;

long long div_ceil(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b + (a % b != 0);
  } else {
    return a / b;
  }
}

long long div_floor(long long a, long long b) {
  if ((a >= 0 and b >= 0) or (a < 0 and b < 0)) {
    return a / b;
  } else {
    return a / b - (a % b != 0);
  }
}

int main() {
  long long n, k; cin>>n>>k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin>>a[i];
  sort(a.begin(), a.end());

  long long ok = 1e18, ng = -1e18-1;
  while (ng + 1 < ok) {
    long long mid = (ok + ng) / 2;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) {
        long long v = div_ceil(mid, a[i]);
        cnt += a.begin() + i - lower_bound(a.begin(), a.begin() + i, v);
      } else if (a[i] == 0) {
        if (mid >= 0) cnt += i;
      } else {
        long long v = div_floor(mid, a[i]);
        cnt += upper_bound(a.begin(), a.begin() + i, v) - a.begin();
      }
    }
    if (cnt >= k) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;

  return 0;
}