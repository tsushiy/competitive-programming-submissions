#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin>>n>>m;
  if (n % 2 == 0) {
    int w = n-1;
    int pos = 1;
    for (int i = 0; i < (m+1)/2; i++) {
      cout << pos << ' ' << pos + w << endl;
      ++pos;
      w -= 2;
    }
    w = 2;
    pos = n/2;
    for (int i = (m+1)/2; i < m; i++) {
      cout << pos << ' ' << pos + w << endl;
      --pos;
      w += 2;
    }
  } else {
    int w = n-1;
    int pos = 1;
    for (int i = 0; i < m; i++) {
      cout << pos << ' ' << pos + w << endl;
      ++pos;
      w -= 2;
    }
  }

  return 0;
}