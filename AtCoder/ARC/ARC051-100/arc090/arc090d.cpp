#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin>>n>>m;
  vector<vector<pair<int, int>>> g;
  vector<int> l(m), r(m), d(m);

  map<int, int> ma;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int lt, rt, dt; cin>>lt>>rt>>dt;
    if (ma.find(lt) == ma.end()) {
      lt = ma[lt] = cnt;
      ++cnt;
    } else {
      lt = ma[lt];
    }
    if (ma.find(rt) == ma.end()) {
      rt = ma[rt] = cnt;
      ++cnt;
    } else {
      rt = ma[rt];
    }
    l[i] = lt;
    r[i] = rt;
    d[i] = dt;
  }

  g.resize(cnt);
  for (int i = 0; i < m; i++) {
    g[l[i]].emplace_back(r[i], d[i]);
    g[r[i]].emplace_back(l[i], -d[i]);
  }

  vector<int> dist(cnt, 1e9+1);
  for (int i = 0; i < cnt; i++) {
    if (dist[i] == 1e9+1) {
      dist[i] = 0;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nx: g[cur]) {
          int pos, diff;
          tie(pos, diff) = nx;
          if (dist[pos] != 1e9+1 and dist[pos] != dist[cur] + diff) {
            cout << "No" << endl;
            return 0;
          } else if (dist[pos] == 1e9+1) {
            dist[pos] = dist[cur] + diff;
            q.push(pos);
          }
        }
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}