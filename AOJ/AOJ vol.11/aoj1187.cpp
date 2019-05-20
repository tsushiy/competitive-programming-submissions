#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  int M, T, P, R;
  while(cin >> M >> T >> P >> R){
    if(M==0) return 0;
    int solved[T][P] = {};
    vector<vector<int>> team(T, vector<int>(3)); // 0:solved, 1:time, 2:team number
    rep(i, T) team[i][2] = -i-1;
    rep(i, R){
      int m, t, p, j;
      cin >> m >> t >> p >> j;
      t--;p--;
      if(j==0){
        if(solved[t][p]<0) team[t][1] += m + 20*abs(solved[t][p]);
        else{
          team[t][1] += m;
        }
        team[t][0] -= 1;
      }
      else solved[t][p] -= 1;
    }
    sort(team.begin(), team.end());
    rep(i, T){
      cout<<-team[i][2];
      if(i!=T-1){
        if(team[i][0]==team[i+1][0] && team[i][1]==team[i+1][1]) cout << "=";
        else cout<<",";
      }
    }
    cout<<endl;
  }
  return 0;
}