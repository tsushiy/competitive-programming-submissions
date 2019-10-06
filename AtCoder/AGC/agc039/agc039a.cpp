#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

int main() {
  string s; cin>>s;
  long long k; cin>>k;
  int n = s.size();

  if (s == string(n, s[0]) or n == 1) {
    print((n * k) / 2);
    return 0;
  }

  int head = 0, tail = 0, mid = 0;
  for (int i = 0; s[i] == s[0]; ++i) ++head;
  for (int i = n-1; s[i] == s[n-1]; --i) ++tail;
  REP(i, head+1, n-tail) {
    if (s[i] == s[i-1]){
      ++mid;
      ++i;
    }
  }
  long long ans = mid*k + head/2 + tail/2;
  if (s[0] == s[n-1]) {
    ans += ((head+tail)/2) * (k-1);
  } else {
    ans += (head/2 + tail/2) * (k-1);
  }
  print(ans);

  return 0;
}