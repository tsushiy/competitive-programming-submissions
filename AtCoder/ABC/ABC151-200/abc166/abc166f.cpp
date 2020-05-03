#include <bits/stdc++.h>
using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
} initializer;

long long n, a, b, c;
vector<string> s;

void rec(int idx, vector<string> &v, long long a, long long b, long long c) {
  if (idx == n) {
    if (a >= 0 and b >= 0 and c >= 0) {
      cout << "Yes" << endl;
      for (auto x: v) cout << x << endl;
      exit(0);
    } else {
      return;
    }
  }
  if (a < 0 or b < 0 or c < 0) return;

  if (s[idx] == "AB") {
    v.emplace_back("A");
    rec(idx+1, v, a+1, b-1, c);
    v.pop_back();
    v.emplace_back("B");
    rec(idx+1, v, a-1, b+1, c);
    v.pop_back();
  } else if (s[idx] == "AC") {
    v.emplace_back("A");
    rec(idx+1, v, a+1, b, c-1);
    v.pop_back();
    v.emplace_back("C");
    rec(idx+1, v, a-1, b, c+1);
    v.pop_back();
  } else {
    v.emplace_back("B");
    rec(idx+1, v, a, b+1, c-1);
    v.pop_back();
    v.emplace_back("C");
    rec(idx+1, v, a, b-1, c+1);
    v.pop_back();
  }
}

int main() {
  cin>>n>>a>>b>>c;
  for (int i = 0; i < n; i++) {
    string st; cin>>st;
    s.emplace_back(st);
  }

  vector<string> v;
  rec(0, v, a, b, c);
  cout << "No" << endl;

  return 0;
}
