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