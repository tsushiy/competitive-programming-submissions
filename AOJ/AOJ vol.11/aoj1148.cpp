#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int Time[10000][1300];
int last[10000][1000];
int N, M;
int r, q;
int t, n, m, s, ts, te, ans;

int main() {
  while(cin >> N >> M){
    if(N==0) break;
    memset(Time, 0, sizeof(Time));
    memset(last, 0, sizeof(last));

    cin >> r;
    rep(i, r){
      cin >> t >> n >> m >> s;
      n--; m--;
      if(s==1) last[m][n] = t;
      else REP(j, last[m][n], t) Time[m][j] = 1;
    }
    cin >> q;
    rep(i, q){
      ans = 0;
      cin >> ts >> te >> m;
      m--;
      REP(j, ts, te) ans += Time[m][j];
      cout << ans << endl;
    }
  }
  return 0;
}