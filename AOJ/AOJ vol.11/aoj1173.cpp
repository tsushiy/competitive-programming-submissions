#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int main() {
  string s;
  while(getline(cin, s)){
    if(s[0]=='.') return 0;
    stack<char> st;
    bool good = true;
    for(auto e: s){
      if(e=='(' || e=='[') st.push(e);
      else if(e==')' || e==']'){
        if(st.size()==0){
          good = false;
          break;
        }
        else if((e==')' && st.top()=='(') || (e==']' && st.top()=='[')) st.pop();
        else{
          good = false;
          break;
        }
      }
    }
    if(good==true && st.size()==0) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}