n = int(input())
s, p = [], []
for i in range(n):
  st, pt = input().split()
  s.append(st)
  p.append(int(pt))
m = sum(p)/2
for i in range(n):
  if p[i]>m:
    print(s[i])
    exit()
print("atcoder")