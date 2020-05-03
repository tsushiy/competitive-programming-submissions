#include <bits/stdc++.h>
using namespace std;

int n, m, q;
long long ans = 0;
vector<int> a(50), b(50), c(50), d(50);

void calc(vector<int> &A) {
  long long cur = 0;
  for (int i = 0; i < q; i++) {
    if (A[a[i]-1] + c[i] == A[b[i]-1]) cur += d[i];
  }
  ans = max(ans, cur);
}

void rec(vector<int> &A, int idx) {
  if (idx < n) {
    for (int nx = A[idx-1]; nx <= m; nx++) {
      A.emplace_back(nx);
      rec(A, idx+1);
      A.pop_back();
    }
  } else {
    calc(A);
  }
}

int main() {
  cin>>n>>m>>q;
  for (int i = 0; i < q; i++) cin>>a[i]>>b[i]>>c[i]>>d[i];

  vector<int> A({1});
  rec(A, 1);
  cout << ans << endl;

  return 0;
}