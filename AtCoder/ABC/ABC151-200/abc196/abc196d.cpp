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

int n, h, w, a, b;
long long ans = 0;

void rec(vector<int> &v, int i, int rem_a, int rem_b) {
  vector<int> vv(v.begin(), v.end());

  if (rem_a == 0 and rem_b == 0) {
    ++ans;
    return;
  }

  // Aを横に詰める
  int hi = i / w;
  int wi = i % w;
  if (wi < w - 1 and v[i] == 0 and v[i + 1] == 0 and rem_a > 0) {
    vv[i] = vv[i + 1] = 1;
    rec(vv, i + 1, rem_a - 1, rem_b);
    vv[i] = vv[i + 1] = 0;
  }
  // Aを縦に詰める
  if (hi < h - 1 and v[i] == 0 and v[i + w] == 0 and rem_a > 0) {
    vv[i] = vv[i + w] = 1;
    rec(vv, i + 1, rem_a - 1, rem_b);
    vv[i] = vv[i + w] = 0;
  }
  // Bを詰める
  if (v[i] == 0 and rem_b > 0) {
    vv[i] = 1;
    rec(vv, i + 1, rem_a, rem_b - 1);
    vv[i] = 0;
  }
  if (v[i] == 1 and i < n) {
    rec(vv, i + 1, rem_a, rem_b);
  }
}

int main() {
  cin >> h >> w >> a >> b;
  n = h * w;

  vector<int> v(n, 0);  // 0, 1

  rec(v, 0, a, b);
  print(ans);

  return 0;
}
