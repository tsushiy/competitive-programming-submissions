#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)
template<class T, class U>inline bool chmin(T &a, U const &b) { if(b<a){ a=b;return 1; } return 0; }

int N, M, a, b;
long long c;
bool flag;
long long graph[1000];
vector<tuple<int, int, long long>> edge;

int main() {
  cin >> N >> M;
  rep(i, M){
    cin >> a >> b >> c;
    a--; b--;
    edge.push_back(make_tuple(a, b, -c));
  }

  rep(i, N) graph[i] = INF;
  graph[0] = 0;

  rep(i, N*2){
    flag = false;
    for (auto e : edge){
      a = get<0>(e); b = get<1>(e); c = get<2>(e);
      if (chmin(graph[b], graph[a]+c)){
        if (b==N-1) flag = true;
      }
    }
  }

  if (flag) cout << "inf" << endl;
  else cout << -graph[N-1] << endl;
  return 0;
}