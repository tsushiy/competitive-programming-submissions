#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

bool intersect(int x1, int y1, int r1, int x2, int y2, int r2){
  return pow(r1+r2, 2) > pow(x1-x2, 2)+pow(y1-y2, 2);
}

int main() {
  int n;
  while(cin >> n){
    if(n==0) return 0;

    vector<int> x(n), y(n), r(n), c(n), on(n, 0);

    rep(i, n){
      int xt, yt, rt, ct;
      cin >> xt >> yt >> rt >> ct;
      x[i]=xt, y[i]=yt, r[i]=rt, c[i]=ct;
      rep(j, i) if(intersect(xt, yt, rt, x[j], y[j], r[j])) on[i] |= (1<<j);
    }

    vector<int> dp(1<<n, -1);
    dp[0] = 0;
    int ans = 0;

    rep(i, 1<<n){
      if(dp[i]==-1) continue;
      ans = max(ans, dp[i]);

      rep(j, n-1){
        if((i&(1<<j))!=0 || (i&on[j])!=on[j]) continue;
        REP(k, j+1, n){
          if((i&(1<<k))!=0 || (i&on[k])!=on[k] || c[j]!=c[k]) continue;
          int next = (i|(1<<j))|(1<<k);
          dp[next] = max(dp[next], dp[i]+2);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}