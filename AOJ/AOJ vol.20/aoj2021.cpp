#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

long long dist[100][100];
int N, M, L, K, A, H;

int main() {
  while(cin>>N>>M>>L>>K>>A>>H){
    if(N==0) break;

    rep(i, N)rep(j, N){
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = INF;
    }
    bool isFridge[100]={};

    rep(i, L){
      int lt; cin>>lt;
      isFridge[lt] = true;
    }
    isFridge[A]=true; isFridge[H]=true;
    rep(i, K){
      int x, y, t; cin>>x>>y>>t;
      dist[x][y] = t;
      dist[y][x] = t;
    }

    rep(k, N)rep(i, N)rep(j, N){
      dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }

    rep(i, N)rep(j, N){
      if(dist[i][j]>M || !isFridge[i] || !isFridge[j]){
        dist[i][j] = INF;
      }
    }

    rep(k, N)rep(i, N)rep(j, N){
      dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }

    if(dist[H][A]==INF) cout<<"Help!"<<endl;
    else if(dist[H][A]<=M) cout<<dist[H][A]<<endl;
    else cout<<dist[H][A]*2-M<<endl;
  }

  return 0;
}