#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n;
  cin >> n;
  rep(i, n){
    int y, m, d;
    cin >> y >> m >> d;
    int ans=0;
    while(y<1000){
      ans++;
      d++;
      if (d>20){
        d = 1; m++;
      }
      else if(m%2==0 && y%3!=0 && d>19){
        d = 1; m++;
      }
      if(m>10){
        m = 1; y++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}