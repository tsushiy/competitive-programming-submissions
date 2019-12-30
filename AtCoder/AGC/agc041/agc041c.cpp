#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << "\n";
    os << *it;
  }
  return os;
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

vector<string> b3 = {
  "aa.",
  "..b",
  "..b"
};
vector<string> b4 = {
  "abcc",
  "abdd",
  "eegh",
  "ffgh"
};
vector<string> b5 = {
  ".aabc",
  "d..bc",
  "d.eef",
  "ggh.f",
  "iihjj"
};
vector<string> b6 = {
  "aabcc.",
  "d.b..f",
  "dee..f",
  "gg.hhi",
  "..jk.i",
  "..jkll"
};
vector<string> b7 = {
  "abbcc..",
  "a.dee..",
  "ffd..gg",
  "hi...jj",
  "hi...kk",
  "..lmn..",
  "..lmn.."
};

void fill(int k, int x, vector<string> &board) {
  if (k == 4) rep(i, 4) rep(j, 4) board[x+i][x+j] = b4[i][j];
  if (k == 5) rep(i, 5) rep(j, 5) board[x+i][x+j] = b5[i][j];
  if (k == 6) rep(i, 6) rep(j, 6) board[x+i][x+j] = b6[i][j];
  if (k == 7) rep(i, 7) rep(j, 7) board[x+i][x+j] = b7[i][j];
}

int main() {
  int n; cin>>n;
  vector<string> board(n, string(n, '.'));

  if (n == 2) {
    print(-1);
  } else if (n == 3) {
    print(b3);
  } else {
    int r = n % 4 + 4;
    int m = (n - r) / 4;
    rep(i, m) fill(4, i*4, board);
    fill(r, m*4, board);
    print(board);
  }

  return 0;
}