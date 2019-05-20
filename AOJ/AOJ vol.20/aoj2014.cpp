#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int w, h;
char a[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

tuple<int, int, int> dfs(int y, int x){
  if(a[y][x]=='.') a[y][x]='#';
  int res=1, wcnt=0, bcnt=0;
  int rest, bct, wct;

  rep(i,4){
    int nx = x+dx[i], ny = y+dy[i];
 
    if(0<=nx and nx<w and 0<=ny and ny<h and a[ny][nx]!='#'){
      if(a[ny][nx]=='.'){
        tie(wct, bct, rest) = dfs(ny, nx);
        wcnt += wct;
        bcnt += bct;
        res += rest;
      }
      else if(a[ny][nx]=='W') wcnt += 1;
      else if(a[ny][nx]=='B') bcnt += 1;
    }
  }
  return forward_as_tuple(wcnt, bcnt, res);
}

int main() {
  int wcnt, bcnt, res;
  while(true){
    cin>>w>>h;
    if(w==0) break;

    int bans=0, wans=0;

    rep(i,h)rep(j,w){
      cin>>a[i][j];
    }
    rep(i,h)rep(j,w){
      if(a[i][j]=='.'){
        tie(wcnt, bcnt, res) = dfs(i,j);
        //cout<<i<<" "<<j<<" "<<bcnt<<" "<<wcnt<<" "<<res<<" "<<endl;
        if(wcnt>0 and bcnt==0) wans += res;
        else if(wcnt==0 and bcnt>0) bans += res;
      }
    }
    cout<<bans<<" "<<wans<<endl;
  }
  return 0;
}