n, k = list(map(int, input().split()))
ans = 0
for i in range(1, n+1):
  cur = i
  cnt = 0
  while cur<k:
    cur *= 2
    cnt += 1
  ans += pow(2, -cnt)/n
print(ans)