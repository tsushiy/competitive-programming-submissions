#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  string a;
  int l;
  while(cin >> a >> l){
    if(l==0) return 0;
    vector<int> v;
    v.push_back(stoi(a));
    int i=0;
    bool good = false;
    while(not good){
      i++;
      string z;
      rep(j, l-a.size()) z += '0';
      a = z + a;

      sort(a.begin(), a.end());
      int small = stoi(a);
      sort(a.begin(), a.end(), greater<char>());
      int large = stoi(a);
      int t = large - small;
      rep(j, v.size()){
        if(v[j]==t){
          cout << j <<" " << t << " " << i-j << endl;
          good = true;
          break;
        }
      }
      v.push_back(t);
      a = to_string(t);
    }
  }
  return 0;
}