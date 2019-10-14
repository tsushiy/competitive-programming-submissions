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
  int n, m, W; cin>>n>>m>>W;
  vector<pair<int, int>> wv(n);
  rep(i, n) cin>>wv[i].first>>wv[i].second;

  UnionFind uf(n);
  rep(i, m) {
    int a, b; cin>>a>>b;
    --a; --b;
    uf.unite(a, b);
  }
  rep(i, n) {
    int root = uf.find(i);
    if (root != i) {
      wv[root].first += wv[i].first;
      wv[root].second += wv[i].second;
      wv[i].first = wv[i].second = 0;
    }
  }

  int dp[10010];
  rep(i, 10010) dp[i] = -1;
  dp[0] = 0;
  rep(i, n) {
    RREP(j, 10000, 0) if (dp[j] != -1 and j+wv[i].first <= W) {
      dp[j+wv[i].first] = max(dp[j+wv[i].first], dp[j]+wv[i].second);
    }
  }
  int ans = 0;
  rep(i, W+1) ans = max(ans, dp[i]);
  print(ans);

  return 0;
}