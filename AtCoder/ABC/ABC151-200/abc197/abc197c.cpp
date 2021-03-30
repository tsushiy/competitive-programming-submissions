#include <bits/stdc++.h>
using namespace std;
#define REP(i, e) for (int i = 0; i < (e); ++i)
#define REP3(i, b, e) for (int i = (b); i < (e); ++i)
#define RREP(i, b, e) for (int i = (b)-1; i >= e; --i)

inline void print(void) {
  std::cout << '\n';
}

template <class T, class... U>
inline void print(const T &x, const U &...y) {
  std::cout << x;
  if (sizeof...(U) != 0) {
    std::cout << ' ';
  }
  print(y...);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  int ans = 1 << 30;

  REP(i, 1 << (n - 1)) {
    vector<int> v;
    int t = a[0];
    REP3(j, 1, n) {
      if (i >> (j - 1) & 1) {
        t |= a[j];
      } else {
        v.emplace_back(t);
        t = a[j];
      }
    }
    if (t != 0) v.emplace_back(t);

    int cur = 0;
    for (auto x : v) {
      cur ^= x;
    }
    ans = min(ans, cur);
  }
  print(ans);

  return 0;
}
