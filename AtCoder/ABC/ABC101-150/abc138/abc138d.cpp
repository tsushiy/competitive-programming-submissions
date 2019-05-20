#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int dd[200010] = {};
vector<vector<int>> d(200010);
int ans[200010] = {};
int n, q, a, b, p, x;
int tmp;

void dfs(int x, int tmp){
  ans[x] += tmp;
  for(auto next: d[x]){
    dfs(next, tmp+dd[next]);
  }
}

int main() {
  cin>>n>>q;
  rep(i, n-1){
    cin>>a>>b;
    d[a].emplace_back(b);
  }
  rep(i, q){
    cin>>p>>x;
    dd[p] += x;
  }
  dfs(1, dd[1]);
  REP(i, 1, n){
    cout<<ans[i]<<" ";
  }
  cout<<ans[n]<<endl;
  return 0;
}