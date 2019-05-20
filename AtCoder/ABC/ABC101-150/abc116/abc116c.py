n = int(input())
h = list(map(int, input().split()))
ans = 0
for i in range(1, 110):
  flag = False
  for j in range(n):
    if (flag and h[j]<i) or (j==n-1 and h[j]>=i):
      ans += 1
      flag = False
    elif h[j]>=i:
      flag = True
print(ans)