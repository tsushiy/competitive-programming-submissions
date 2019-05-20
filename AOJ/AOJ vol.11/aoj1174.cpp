#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

struct UnionFind{
  vector<int> par;
  vector<int> rank;
  vector<int> sizes;

  UnionFind(int n) : par(n, -1), rank(n, 0), sizes(n, 1){}

  int find(int x){
    if(par[x] < 0) return x;
    else return par[x] = find(par[x]);
  }

  bool unite(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return false;
    else if(rank[x]<rank[y]){
      par[x] = y;
      sizes[y] += sizes[x];
    }
    else if(rank[x]>rank[y]){
      par[y] = x;
      sizes[x] += sizes[y];
    }
    else{
      par[y] = x;
      rank[x] += 1;
      sizes[x] += sizes[y];
    }
    return true;
  }

  bool same(int x, int y){
    return find(x)==find(y);
  }

  int size(int x){
    return sizes[find(x)];
  }
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int h, w, c;
  while(cin >> h >> w >> c){
    if(h==0) return 0;

    int ans=0;
    UnionFind uf(h*w);
    vector<vector<int>> board(h, vector<int>(w));

    rep(i, h)rep(j, w){
      int t; cin >> t;
      board[i][j] = t;
    }

    rep(i, h)rep(j, w)rep(t, 4){
      if(0<=i+dy[t] && i+dy[t]<h && 0<=j+dx[t] && j+dx[t]<w && board[i][j]==board[i+dy[t]][j+dx[t]]){
        uf.unite(w*i+j, w*(i+dy[t])+j+dx[t]);
      }
    }

    REP(c1, 1, 7)REP(c2, 1, 7)REP(c3, 1, 7)REP(c4, 1, 7){
      if(c1==c2 || c2==c3 || c3==c4 || c4==c) continue;
      int cs[] = {c1, c2, c3, c4, c};
      UnionFind uft = uf;
      rep(cc, 5)rep(i, h)rep(j, w){
        int ct = cs[cc];
        if(uft.same(w*i+j, 0)){
          rep(t, 4){
            if(0<=i+dy[t] && i+dy[t]<h && 0<=j+dx[t] && j+dx[t]<w && ct==board[i+dy[t]][j+dx[t]]){
              uft.unite(w*i+j, w*(i+dy[t])+j+dx[t]);
            }
          }
        }
      }
      ans = max(ans, uft.size(0));
    }
    cout << ans << endl;
  }
  return 0;
}
