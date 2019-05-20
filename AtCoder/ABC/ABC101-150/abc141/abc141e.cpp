#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n;
  string s;
  cin>>n;
  cin>>s;
  int ok = 0, ng = n/2+1;
  while (ok+1 < ng) {
    int mid = (ok+ng)/2;
    bool flag = false;
    rep(j, n-mid) {
      if ((s.substr(j+mid)).find(s.substr(j, mid)) != string::npos) {
        flag = true;
        break;
      }
    }
    if (flag) ok = mid;
    else ng = mid;
  }
  cout<<ok<<endl;
  return 0;
}