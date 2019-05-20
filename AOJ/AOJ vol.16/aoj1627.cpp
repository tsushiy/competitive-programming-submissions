#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int n, m, ans, match[9][9];

bool check(int y){
  int win=0, lose=0;
  rep(x, n){
    if(match[y][x]==1) win++;
    else if(match[y][x]==-1) lose++;
  }
  return (win<=(n-1)/2 && lose<=(n-1)/2);
}

void dfs(int cur){
  int x = cur%n;
  int y = cur/n;

  if(cur==n*n){
    ans++; return;
  }

  if(x==y || match[y][x]!=0){
    if(check(y)) dfs(cur+1);
    return;
  }

  match[y][x] = 1; match[x][y] = -1;
  if(check(y)) dfs(cur+1);

  match[y][x] = -1; match[x][y] = 1;
  if(check(y)) dfs(cur+1);

  match[y][x] = match[x][y] = 0;
}

int main() {
  while(cin>>n){
    if(n==0) return 0;

    memset(match, 0, sizeof(match));

    cin >> m;
    rep(i, m){
      int x, y; cin >> x >> y;
      x--; y--;
      match[x][y] = 1;
      match[y][x] = -1;
    }

    ans = 0;
    dfs(0);
    cout<<ans<<endl;
  }
  return 0;
}