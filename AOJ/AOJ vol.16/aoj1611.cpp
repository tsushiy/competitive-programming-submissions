#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int n, u, v;
int w[310];
int dp[310][310];

int main() {
  while(true){
    cin>>n;
    if(n==0) break;
    rep(i,n) w[i]=0;
    rep(i,n) cin>>w[i];

    rep(i,310)rep(j,310) dp[i][j]=0;
    rep(i,n-1){
      if(abs(w[i+1]-w[i])<=1) dp[i][i+1]=2;
    }
    REP(k,3,n+1){
      rep(i,n-k+1){
        if(dp[i+1][i+k-1]>1 && abs(w[i]-w[i+k])<=1) dp[i][i+k]=k+1;
        rep(j,k){
          if(dp[i][i+j]>1 && dp[i+j+1][i+k]>1){
            dp[i][i+k]=k+1;
          }
        }
      }
    }
    rep(i,n)REP(j,i+1,n)REP(k,i,j){
      dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
    }
    cout<<dp[0][n-1]<<endl;
  }
  return 0;
}