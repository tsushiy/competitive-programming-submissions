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
  vector<long long> x(n), c(n);
  REP(i, n) cin >> x[i] >> c[i];

  vector<vector<long long>> vals(n + 1, vector<long long>());
  REP(i, n) { vals[c[i] - 1].emplace_back(x[i]); }
  vals[n].emplace_back(0);
  REP(i, n + 1) sort(vals[i].begin(), vals[i].end());

  long long left = 0, right = 0;
  long long min_left_cost = 0, min_right_cost = 0;
  REP(i, n + 1) {
    if (vals[i].empty()) continue;
    long long cur;
    long long next_left, next_right;

    // 左 -> 左
    cur = left;
    long long ll_cost = min_left_cost;
    for (int j = vals[i].size() - 1; j >= 0; --j) {
      ll_cost += abs(vals[i][j] - cur);
      cur = vals[i][j];
    }

    // 右 -> 左
    cur = right;
    long long rl_cost = min_right_cost;
    for (int j = vals[i].size() - 1; j >= 0; --j) {
      rl_cost += abs(vals[i][j] - cur);
      cur = vals[i][j];
    }
    next_left = cur;

    // 右 -> 右
    cur = right;
    long long rr_cost = min_right_cost;
    for (int j = 0; j < vals[i].size(); ++j) {
      rr_cost += abs(vals[i][j] - cur);
      cur = vals[i][j];
    }

    // 左 -> 右
    cur = left;
    long long lr_cost = min_left_cost;
    for (int j = 0; j < vals[i].size(); ++j) {
      lr_cost += abs(vals[i][j] - cur);
      cur = vals[i][j];
    }
    next_right = cur;

    min_left_cost = min(ll_cost, rl_cost);
    min_right_cost = min(rr_cost, lr_cost);

    left = next_left;
    right = next_right;
  }

  print(min(min_left_cost, min_right_cost));

  return 0;
}
