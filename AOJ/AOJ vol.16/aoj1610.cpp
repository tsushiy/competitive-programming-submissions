#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int m, n;
  while(cin >> m >> n){
    if(m==0) return 0;
    bool num[8000000]={};

    rep(i, n){
      while(num[m]==1) m++;
      for(int j=1; j*m<8000000; j++){
        num[j*m] = true;
      }
    }
    while(num[m]==1) m++;
    cout << m << endl;
  }
  return 0;
}