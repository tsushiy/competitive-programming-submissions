#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n;
  while(cin>>n){
    if(n==0) return 0;

    int draw = (n-1)/2;

    vector<vector<int>> match(n, vector<int>(n, 0));
    vector<int> wins(n, 0);

    int m; cin >> m;
    rep(i, m){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      match[x][y] = 1;
      match[y][x] = -1;
      wins[x] += 1;
    }

    int ans = 0;
    int rm = n*(n-1)/2-m;
    rep(i, 1<<rm){
      int cur = 0;
      bool good = true;
      vector<int> wint = wins;
      rep(j, n-1){
        if(good==false || cur>=rm) break;
        REP(k, j+1, n){
          if(wint[j]>draw || wint[k]>draw){
            good = false;
            break;
          }
          if(cur>=rm) break;
          if(match[j][k]==0){
            if((i&(1<<cur))!=0){
              wint[j]++;
              if(wint[j] > draw){
                good = false;
                break;
              }
            }
            else{
              wint[k]++;
              if(wint[k] > draw){
                good = false;
                break;
              }
            }
            cur++;
          }
        }
      }
      if(good) ans+=1;
    }
    cout<<ans<<endl;
  }

  return 0;
}