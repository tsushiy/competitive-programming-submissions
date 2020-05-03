#include <bits/stdc++.h>
using namespace std;

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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int h, w; cin>>h>>w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) cin>>s[i];
  UnionFind uf(h*w);

  queue<int> q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') q.push(i*w+j);
    }
  }

  while (!q.empty()) {
    int t = q.front(); q.pop();
    int y = t / w, x = t % w;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx and nx < w and 0 <= ny and ny < h) {
        if (s[y][x] != s[ny][nx] and not uf.same(y*w+x, ny*w+nx)) {
          q.push(ny*w + nx);
          uf.unite(y*w+x, ny*w+nx);
        }
      }
    }
  }

  vector<int> white(h*w, 0), black(h*w, 0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int root = uf.find(i*w + j);
      if (s[i][j] == '#') ++black[root];
      else ++white[root];
    }
  }

  long long ans = 0;
  for (int i = 0; i < h*w; i++) ans += (long long)white[i]*black[i];
  cout << ans << endl;

  return 0;
}