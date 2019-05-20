#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int n;
  while(cin >> n){
    if(n==0) return 0;

    vector<pair<int, int>> v(n);
    v[0].first = 0, v[0].second = 0;

    int xmax=0, xmin=0, ymax=0, ymin=0;
    REP(i, 1, n){
      int m, d;
      cin >> m >> d;
      if(d==0){
        v[i].first = v[m].first-1;
        v[i].second = v[m].second;
      }
      else if(d==1){
        v[i].first = v[m].first;
        v[i].second = v[m].second-1;
      }
      else if(d==2){
        v[i].first = v[m].first+1;
        v[i].second = v[m].second;
      }
      else if(d==3){
        v[i].first = v[m].first;
        v[i].second = v[m].second+1;
      }
      xmax = max(xmax, v[i].first);
      xmin = min(xmin, v[i].first);
      ymax = max(ymax, v[i].second);
      ymin = min(ymin, v[i].second);
    }
    cout<<xmax-xmin+1<<" "<<ymax-ymin+1<<endl;
  }
  return 0;
}