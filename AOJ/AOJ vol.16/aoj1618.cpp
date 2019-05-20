#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int d, w;
  while(cin >> d >> w){
    if(d==0) return 0;
    int grid[d][w] = {};
    rep(i,d)rep(j,w) cin>>grid[i][j];
    int ans=0;

    rep(i, d-2)rep(j, w-2){
      for(int dd=2; i+dd<d; dd++){
        for(int ww=2; j+ww<w; ww++){
          int wmin = 1e9;
          int cur = 0;
          int good = true;
          REP(ii, i, i+dd+1){
            wmin = min(wmin, grid[ii][j]);
            wmin = min(wmin, grid[ii][j+ww]);
          }
          REP(jj, j, j+ww+1){
            wmin = min(wmin, grid[i][jj]);
            wmin = min(wmin, grid[i+dd][jj]);
          }
          REP(ii, i+1, i+dd)REP(jj, j+1, j+ww){
            if(grid[ii][jj]>=wmin){
              good = false;
              break;
            }
            else cur += wmin - grid[ii][jj];
          }
          if(good) ans = max(ans, cur);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}