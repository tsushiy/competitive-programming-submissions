#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n;
  while(cin >> n){
    if(n==0) return 0;
    int a[26]={};
    vector<char> v(n);
    rep(i, n) cin >> v[i];
    rep(i, n){
      a[v[i]-'A'] += 1;
      int first=0, second=0, t;
      char c;
      rep(j, 26){
        if(a[j]>first){
          first = a[j];
          t = j;
          c = 'A'+j;
        }
      }
      rep(j, 26){
        if(a[j]>second && j!=t){
          second = a[j];
        }
      }
      if(first>n-i-1+second){
        cout << c << " " << i+1 << endl;
        break;
      }
      if(i==n-1) puts("TIE");
    }
  }
  return 0;
}