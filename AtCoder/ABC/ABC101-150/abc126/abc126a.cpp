#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s[--k] += 'a'-'A';
  cout << s << endl;
  return 0;
}