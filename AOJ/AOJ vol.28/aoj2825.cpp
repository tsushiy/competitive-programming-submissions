#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int n, m, s, k, c;

int main() {
  while(cin>>n>>m){
    if(n==0) return 0;
    int ma[10010]={}, mi[10010]={};

    rep(i, m){
      cin>>s>>k;
      rep(j,k){
        cin>>c; c--;
        ma[c]+=s;
        if(k==1) mi[c]+=s;
      }
    }
    int ans = 0;
    rep(i, n)rep(j, n){
      if(i!=j) ans=max(ans, ma[i]-mi[j]+1);
    }
    cout<<ans<<endl;
  }
  return 0;
}