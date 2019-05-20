#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

struct UnionFind{
  vector<int> par;
  vector<int> rank;

  UnionFind(int n) : par(n, -1), rank(n, 0){}

  int find(int x){
    if(par[x] < 0) return x;
    else return par[x] = find(par[x]);
  }

  bool unite(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return false;
    else if(rank[x]<rank[y]) par[x] = y;
    else if(rank[x]>rank[y]) par[y] = x;
    else par[y] = x, rank[x] += 1;
    return true;
  }

  bool same(int x, int y){
    return find(x)==find(y);
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n+1);
  int ans = 0;
  rep(i, m){
    int x, y, z;
    cin >> x >> y >> z;
    ans += uf.unite(x, y);
  }
  cout << n-ans << endl;
  return 0;
}