n = int(input())
a = list(map(int, input().split()))
ans = float("inf")
for i in range(-100, 101):
  cost=0
  for j in range(n):
    cost+=(a[j]-i)*(a[j]-i)
  if cost<ans:
    ans=cost
print(ans)