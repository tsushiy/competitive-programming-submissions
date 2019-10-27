n = int(input())
ans = float("INF")
for i in range(1, 1000100):
  if (n%i == 0):
    j = n//i
    ans = min(ans, i+j-2)
print(ans)