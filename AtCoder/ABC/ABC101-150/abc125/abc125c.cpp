#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;++i)
template<class T, class U>inline bool chmax(T &a, U const &b) { if(a<b){ a=b;return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, U const &b) { if(b<a){ a=b;return 1; } return 0; }

long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b): a;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }

  vector<int> left(n + 1, 0), right(n + 1, 0);
  rep(i, n) {
    left[i + 1] = gcd(a[i], left[i]);
    right[n - i - 1] = gcd(a[n - i - 1], right[n - i]);
  }

  long long ans = 0;
  rep(i, n) { chmax(ans, gcd(left[i], right[i + 1])); }
  cout << ans << endl;
  return 0;
}