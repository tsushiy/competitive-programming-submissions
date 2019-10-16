#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

vector<int> b(6), c(6);
string g(9, '_');
int sum = 0;

int calc(string s) {
  int ret = 0;
  rep(i, 6) if (s[i] == s[i+3]) ret += b[i];
  int t[6] = {0, 1, 3, 4, 6, 7};
  rep(i, 6) if (s[t[i]] == s[t[i]+1]) ret += c[i];
  return ret;
}

int dfs(string s, int n) {
  if (n == 9) return sum-calc(s);

  int ret = -1<<30;
  rep(i, 9) {
    if (s[i] != '_') continue;
    string t = s;

    if (n % 2 == 0) t[i] = 'o';
    else t[i] = 'x';
    ret = max(ret, sum - dfs(t, n+1));
  }
  return ret;
}

int main() {
  rep(i, 6) cin>>b[i];
  rep(i, 6) cin>>c[i];
  rep(i, 6) sum += b[i];
  rep(i, 6) sum += c[i];

  int ans = dfs(g, 0);
  print(ans);
  print(sum-ans);

  return 0;
}