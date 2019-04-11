s = input()
ans = float("INF")
from string import ascii_lowercase
for c in ascii_lowercase:
  cnt = 0
  st = s[:]
  while True:
    snew = ""
    if len(set(st))==1:
      break
    for i in range(len(st)-1):
      if st[i]==c or st[i+1]==c:
        snew += c
      else:
        snew += st[i]
    cnt+=1
    st = snew[:]
  ans = min(ans, cnt)
print(ans)