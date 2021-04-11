#include <bits/stdc++.h>
using namespace std;
#define REP(i, e) for (int i = 0; i < (e); ++i)
#define REP3(i, b, e) for (int i = (b); i < (e); ++i)
#define RREP(i, b, e) for (int i = (b)-1; i >= e; --i)

struct Initializer {
  Initializer() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cout << std::fixed << std::setprecision(15) << std::boolalpha;
  }
} initializer;

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

string s1, s2, s3;
int n1, n2, n3;
map<char, int> ma;  // char -> int

bool init() {
  cin >> s1 >> s2 >> s3;
  n1 = s1.size();
  n2 = s2.size();
  n3 = s3.size();

  int cnt = 1;
  REP(i, n1) {
    if (ma[s1[i]] == 0) {
      ma[s1[i]] = cnt;
      ++cnt;
    }
  }
  REP(i, n2) {
    if (ma[s2[i]] == 0) {
      ma[s2[i]] = cnt;
      ++cnt;
    }
  }
  REP(i, n3) {
    if (ma[s3[i]] == 0) {
      ma[s3[i]] = cnt;
      ++cnt;
    }
  }

  if (cnt > 11) {
    return false;
  }

  for (auto &x : ma) {
    --x.second;
  }

  return true;
}

bool solve() {
  vector<int> v(10, 0);
  iota(v.begin(), v.end(), 0);

  do {
    long long m1 = 0, m2 = 0, m3 = 0;
    int t;
    bool ok = true;

    REP(i, n1) {
      m1 *= 10;
      t = v[ma[s1[i]]];
      if (i == 0 and t == 0) ok = false;
      m1 += t;
    }
    REP(i, n2) {
      m2 *= 10;
      t = v[ma[s2[i]]];
      if (i == 0 and t == 0) ok = false;
      m2 += t;
    }
    REP(i, n3) {
      m3 *= 10;
      t = v[ma[s3[i]]];
      if (i == 0 and t == 0) ok = false;
      m3 += t;
    }

    if (!ok) continue;
    if (m1 + m2 == m3) {
      REP(i, n1) cout << v[ma[s1[i]]];
      cout << endl;
      REP(i, n2) cout << v[ma[s2[i]]];
      cout << endl;
      REP(i, n3) cout << v[ma[s3[i]]];
      cout << endl;
      return true;
    }
  } while (next_permutation(v.begin(), v.end()));

  return false;
}

int main() {
  if (!init()) {
    print("UNSOLVABLE");
    return 0;
  }
  if (!solve()) {
    print("UNSOLVABLE");
  };

  return 0;
}
