n = int(input())
s = [list(input().split()) for i in range(n)]
for i in range(n):
  s[i].append(i+1)
s.sort(key=lambda x: int(x[1]), reverse=True)
s.sort(key=lambda x: x[0])
for e in s:
  print(e[2])