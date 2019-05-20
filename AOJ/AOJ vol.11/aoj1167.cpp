#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int main(){
  int s[200], dp1[MAX], dp2[MAX];
  for(int i=1;i<200;i++) s[i]=i*(i+1)*(i+2)/6;
  for(int i=0;i<MAX;i++){
    dp1[i] = dp2[i] = i;
    for(int j=1;i>=s[j];j++){
      dp1[i] = min(dp1[i], dp1[i-s[j]]+1);
      if(s[j]%2==1){
        dp2[i] = min(dp2[i], dp2[i-s[j]]+1);
      }
    }
  }
  int n;
  while(true){
    cin >> n;
    if(n==0) break;
    cout << dp1[n] << " " << dp2[n] << endl;
  }
  return 0;
}