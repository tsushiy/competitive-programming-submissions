#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

long long dist[200][200];
int N, M, R, a, b, c, rt;

int main() {
  cin >> N >> M >> R;
  vector<int> r;

  rep(i, 200)rep(j, 200){
    if(i==j) dist[i][j] = 0;
    else dist[i][j] = INF;
  }

  rep(i, R){
    cin >> rt;
    r.push_back(--rt);
  }
  rep(i, M){
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }

  rep(k, N)rep(i, N)rep(j, N){
    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
  }

  long long ans = INF;
  sort(r.begin(), r.end());
  do {
    long long cur = 0;
    rep(i, R-1) cur += dist[r[i]][r[i+1]];
    ans = min(ans, cur);
  } while (next_permutation(r.begin(), r.end()));

  cout << ans << endl;
  return 0;
}