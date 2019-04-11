s = input()
from string import ascii_lowercase
a = ascii_lowercase
if s == a[::-1]:
  print(-1)
else:
  if len(set(s))<26:
    for ele in a:
      if ele not in s:
        print(s+ele)
        break
  else:
    suf=[s[-1]]
    for i in range(25, 0, -1):
      if s[i]<s[i-1]:
        suf.append(s[i-1])
      else:
        last = i-1
        break
    suf.sort()
    for i in range(len(suf)):
      if s[last]<suf[i]:
        print(s[:last]+suf[i])
        break