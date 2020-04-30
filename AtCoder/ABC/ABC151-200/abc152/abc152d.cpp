#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  int ans = 0;
  map<pair<int, int>, int> ma;

  for (int i = 1; i <= n; i++) {
    int head = to_string(i)[0] - '0';
    int tail = i % 10;
    ++ma[make_pair(head, tail)];
  }

  for (auto x: ma) {
    int head = x.first.first;
    int tail = x.first.second;
    int a = x.second;
    int b = ma[make_pair(tail, head)];
    ans += a*b;
  }

  cout << ans << endl;

  return 0;
}