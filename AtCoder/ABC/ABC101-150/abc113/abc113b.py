n = int(input())
t, a = list(map(int, input().split()))
h = list(map(int, input().split()))
cur = 1e9
idx = 0
for i in range(n):
  if abs(a-(t-h[i]*0.006))<cur:
    cur = abs(a-(t-h[i]*0.006))
    idx = i+1
print(idx)