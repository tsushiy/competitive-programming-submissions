#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)
int main() {
  int h, w;
  while(cin >> h >> w){
    if(h==0) return 0;
    int l = h*h+w*w;
    int hh=1e9, ww=1e9, ll=1e9;
    for(int i=150; i>0; i--){
      for(int j=150; j>i; j--){
        int tmp = i*i+j*j;
        if(tmp>l){
          if(ll>tmp || (ll==tmp && hh>i)){
            ll = tmp;
            hh = i;
            ww = j;
          }
        }
        else if(tmp==l && i>h){
          if(ll>tmp || (ll==tmp && hh>i)){
            ll = tmp;
            hh = i;
            ww = j;
          }
        }
      }
    }
    cout << hh << " " << ww << endl;
  }
  return 0;
}