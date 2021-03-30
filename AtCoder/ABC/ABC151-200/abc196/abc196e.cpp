#include <bits/stdc++.h>
using namespace std;
#define REP(i, e) for (int i = 0; i < (e); ++i)
#define REP3(i, b, e) for (int i = (b); i < (e); ++i)
#define RREP(i, b, e) for (int i = (b)-1; i >= e; --i)

inline void print(void) {
  cout << '\n';
}

template <class T, class... U>
inline void print(const T &x, const U &...y) {
  cout << x;
  if (sizeof...(U) != 0) {
    cout << ' ';
  }
  print(y...);
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<int> t(n);
  REP(i, n) cin >> a[i] >> t[i];

  int q;
  cin >> q;
  vector<long long> x(q);
  REP(i, q) cin >> x[i];

  long long lo = -1000000000LL;
  long long hi = 1000000000LL;

  long long s = 0;
  REP(i, n) {
    if (t[i] == 1) {
      s += a[i];
      lo += a[i];
      hi += a[i];
    } else if (t[i] == 2) {
      lo = max(lo, a[i]);
      hi = max(hi, a[i]);
    } else if (t[i] == 3) {
      lo = min(lo, a[i]);
      hi = min(hi, a[i]);
    }
  }

  REP(i, q) {
    if (x[i] + s <= lo) {
      print(lo);
    } else if (x[i] + s >= hi) {
      print(hi);
    } else {
      print(x[i] + s);
    }
  }

  return 0;
}
