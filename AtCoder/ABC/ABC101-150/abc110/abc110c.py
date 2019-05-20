from collections import defaultdict
s = input()
t = input()
d1 = defaultdict(set)
d2 = defaultdict(set)
for i in range(len(s)):
  d1[t[i]].add(s[i])
  d2[s[i]].add(t[i])
  if len(d1[t[i]])>1 or len(d2[s[i]])>1:
    print("No")
    exit()
print("Yes")