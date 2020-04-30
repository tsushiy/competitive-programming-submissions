#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  int total = 3;
  for (int i = 0; i < n-1; i++) total *= 3;

  int minus = 1;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if (t % 2 == 0) minus *= 2;
  }

  cout << total - minus << endl;

  return 0;
}