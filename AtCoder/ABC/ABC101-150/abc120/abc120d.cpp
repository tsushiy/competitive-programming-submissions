#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

struct UnionFind{
private:
  vector<int> par, rank, sizes;
public:
  UnionFind(int n) : par(n, -1), rank(n, 0), sizes(n, 1){}
  int find(int x) { return (par[x] < 0) ? x : (par[x] = find(par[x])); }
  bool unite(int x, int y){
    x = find(x), y = find(y);
    if(x==y) return false;
    else if(rank[x]<rank[y]){
      par[x] = y;
      sizes[y] += sizes[x];
    } else if(rank[x]>rank[y]){
      par[y] = x;
      sizes[x] += sizes[y];
    } else{
      par[y] = x;
      rank[x] += 1;
      sizes[x] += sizes[y];
    }
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};

int main() {
  int n, m; cin>>n>>m;
  vector<pair<int, int>> ab(m);
  rep(i, m) {
    int a, b; cin>>a>>b; --a; --b;
    ab[i].first = a; ab[i].second = b;
  }

  vector<long long> ans(m);
  UnionFind uf(n);
  RREP(i, m, 0) {
    if (uf.find(ab[i].first) != uf.find(ab[i].second)) {
      ans[i] = (long long)uf.size(ab[i].first) * uf.size(ab[i].second);
      uf.unite(ab[i].first, ab[i].second);
    }
  }
  rep(i, m-1) ans[i+1] += ans[i];
  rep(i, m) print(ans[i]);

  return 0;
}