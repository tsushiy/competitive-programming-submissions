#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

struct edge{int to, cap, rev;};
int INF = (1<<30);

int m, n;
int b[500], r[500];

vector<edge> G[1010];
int level[1010];
int iter[1010];

void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

void bfs(int s){
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while(!que.empty()){
    int v = que.front(); que.pop();
    for(int i=0; i<(int)G[v].size(); i++){
      edge &e = G[v][i];
      if(e.cap>0 && level[e.to]<0){
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

int dfs(int v, int t, int f){
  if(v==t) return f;
  for(int &i = iter[v]; i<(int)G[v].size(); i++){
    edge &e = G[v][i];
    if(e.cap>0 && level[v]<level[e.to]){
      int d=dfs(e.to, t, min(f, e.cap));
      if(d>0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t){
  int flow = 0;
  for(;;){
    bfs(s);
    if(level[t]<0) return flow;
    memset(iter, 0, sizeof(iter));
    int f;
    while((f=dfs(s, t, INF)) > 0){
      flow += f;
    }
  }
}

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(){
  while(true){
    cin>>m>>n;
    if(m==0) break;

    int s=m+n, t=s+1;
    memset(G, 0, sizeof(G));
    memset(level, 0, sizeof(level));
    memset(iter, 0, sizeof(iter));

    rep(i,m) cin>>b[i];
    rep(j,n) cin>>r[j];

    rep(i,m) add_edge(s, i, 1);
    rep(j,n) add_edge(m+j, t, 1);

    rep(i,m)rep(j,n){
      if(gcd(b[i], r[j])>1){
        add_edge(i, m+j, 1);
      }
    }

    int ans = max_flow(s, t);
    cout<<ans<<endl;
  }
  return 0;
}
