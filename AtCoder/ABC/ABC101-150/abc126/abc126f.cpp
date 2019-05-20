#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int m, k;
  cin >> m >> k;

  if(m==1){
    if(k==0) cout << "0 0 1 1" << endl;
    else cout << -1 << endl;
    return 0;
  }

  if(k>=(1<<m)){
    cout << -1 << endl;
    return 0;
  }

  rep(i, (1<<m)){
    if(i!=k) cout << i << " ";
  }
  cout << k << " ";
  for(int i=(1<<m)-1;i>-1; i--){
    if(i!=k) cout << i << " ";
  }
  cout << k << endl;

  return 0;
}