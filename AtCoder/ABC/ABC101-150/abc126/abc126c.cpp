#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n, k;
  cin >> n >> k;
  double ans = 0;
  REP(i, 1, n+1){
    double tmp = 1;
    for(int j=i; j<k; j*=2) tmp/=2;
    ans += tmp/n;
  }
  cout << setprecision(12) << ans << endl;
  return 0;
}