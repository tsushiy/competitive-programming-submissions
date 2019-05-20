#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

vector<pair<int, int>> edge[100100];
vector<int> graph(100100);

int dfs(int n, int p, int c){
  graph[n] = c;
  for(auto to: edge[n]){
    if(to.first==p) continue;
    if(to.second%2==1) dfs(to.first, n, not c);
    else dfs(to.first, n, c);
  }
}

int main() {
  int n;
  cin >> n;
  rep(i, n){
    int u, v, w;
    cin >> u >> v >> w;
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  dfs(1, -1, 0);
  REP(i, 1, n+1){
    cout << graph[i] << endl;
  }
  return 0;
}