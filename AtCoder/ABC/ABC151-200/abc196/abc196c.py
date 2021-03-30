n = int(input())
ans = 0
for i in range(1, 1000000):
  s = str(i) + str(i)
  x = int(s)
  if x > n:
    break
  ans += 1
print(ans)
