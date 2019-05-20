a = list(map(int, input().split()))
ans = float("INF")

for i in range(3):
  n1 = (a[i]//2)*a[(i+1)%3]*a[(i+2)%3]
  n2 = (a[i]-a[i]//2)*a[(i+1)%3]*a[(i+2)%3]
  ans = min(ans, abs(n1-n2))
print(ans)