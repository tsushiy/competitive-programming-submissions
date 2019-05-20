#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n, m;
  while(cin >> n >> m){
    if(n==0) return 0;
    int ans=0;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    rep(i, n)REP(j, i+1, n){
      int t = v[i]+v[j];
      if(t<=m && ans<t) ans=t;
    }
    if(ans==0) cout << "NONE" << endl;
    else cout << ans << endl;
  }
  return 0;
}