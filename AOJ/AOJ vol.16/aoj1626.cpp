#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int b;
  while(cin >> b){
    if(b==0) return 0;
    for(long long n=100000; n>0; n--){
      long long t = n*(n-1)/2;
      if((b-t)%n==0 && (b-t)/n>0){
        cout << (b-t)/n << " " << n << endl;
        break;
      }
    }
  }
  return 0;
}