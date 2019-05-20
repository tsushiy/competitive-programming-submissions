#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  if(1<=s/100 && s/100<=12 && 1<=s%100 && s%100<=12) puts("AMBIGUOUS");
  else if(1<=s/100 && s/100<=12) puts("MMYY");
  else if(1<=s%100 && s%100<=12) puts("YYMM");
  else puts("NA");
  return 0;
}