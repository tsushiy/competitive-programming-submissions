#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool isBad(vector<bool> &v) {
  for (int i = 0; i < n; i++) {
    int prev = i-1, nxt = i+1;
    if (i == 0) prev = n-1;
    if (i == n-1) nxt = 0;
    if (s[i] == 'o' and v[i] == true and v[prev] != v[nxt]) return true;
    if (s[i] == 'o' and v[i] == false and v[prev] == v[nxt]) return true;
    if (s[i] == 'x' and v[i] == true and v[prev] == v[nxt]) return true;
    if (s[i] == 'x' and v[i] == false and v[prev] != v[nxt]) return true;
  }
  return false;
}

int main() {
  cin>>n>>s;

  for (int i = 0; i < 4; i++) {
    vector<bool> tmp(n);
    if (i == 0) {
      tmp[0] = tmp[1] = false;
    } else if (i == 1) {
      tmp[0] = tmp[1] = true;
    } else if (i == 2) {
      tmp[0] = false;
      tmp[1] = true;
    } else {
      tmp[0] = true;
      tmp[1] = false;
    }
    for (int i = 2; i < n; i++) {
      if ((s[i-1] == 'o' and tmp[i-1] == true) or (s[i-1] == 'x' and tmp[i-1] == false)) {
        tmp[i] = tmp[i-2];
      } else {
        tmp[i] = !tmp[i-2];
      }
    }

    if (!isBad(tmp)) {
      for (int i = 0; i < n; i++) {
        cout << (tmp[i] ? 'S' : 'W');
      }
      cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}