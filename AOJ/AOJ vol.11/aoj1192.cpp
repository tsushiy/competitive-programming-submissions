#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int x, y, s;
  while(cin >> x >> y >> s){
    if(x==0) return 0;
    int ans=0;
    REP(i, 1, s)REP(j, 1, s){
      int t = i*(100+x)/100 + j*(100+x)/100;
      if(t==s){
        int tt = i*(100+y)/100 + j*(100+y)/100;
        if(tt>ans) ans = tt;
      }
    }
    cout << ans << endl;
  }
  return 0;
}