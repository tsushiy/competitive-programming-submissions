#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

#define MAX 250000
vector<int> prime(MAX, 1);

void sieve() {
  prime[0] = prime[1] = 0;
  for(int i=4;i<MAX;i+=2){
    prime[i] = 0;
  }
  for(int i=3;i<sqrt(MAX)+1;i+=2){
    if(prime[i]==1){
      for(int j=i*2;j<MAX;j+=i) prime[j] = 0;
    }
  }
}

int main() {
  sieve();
  vector<int> s(MAX);
  int cur = 0;
  rep(i, MAX){
    if(prime[i]==1) cur++;
    s[i] = cur;
  }
  int n;
  while(cin >> n){
    if(n==0) return 0;
    cout << s[n*2]-s[n] << endl;
  }
  return 0;
}