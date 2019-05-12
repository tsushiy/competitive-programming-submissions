n = int(input())
s = [input() for i in range(n)]
ss = ""
ans = 0
t1, t2, t3 = 0, 0, 0
for e in s:
  ans += e.count("AB")
  if e[0] == "B" and e[-1] == "A":
    t3 += 1
  elif e[0] == "B":
    t1 += 1
  elif e[-1] == "A":
    t2 += 1
if t3:
  ans += t3-1
if t3 and t1:
  t1 -= 1
  ans += 1
if t3 and t2:
  t2 -= 1
  ans += 1
ans += max(0, min(t1, t2))
print(ans)