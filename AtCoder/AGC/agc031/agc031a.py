n = int(input())
s = input()
MOD = 10**9+7

from collections import defaultdict
import string
d = defaultdict(int)
let = string.ascii_lowercase

for ele in s:
  d[ele] += 1

ans = 1
for i in range(26):
  if d[let[i]]>0:
    ans = (ans*(d[let[i]]+1))%MOD
print(ans-1)