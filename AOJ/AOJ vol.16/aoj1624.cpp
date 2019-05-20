#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n;
  while(cin >> n){
    if(n==0) return 0;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int sum = accumulate(v.begin(), v.end(), 0);
    int cnt = 0;
    rep(i, n){
      if(v[i]<=sum/n) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}