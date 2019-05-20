n = int(input())
w = list(map(int, input().split()))
ans = 1e9
s = [0 for i in range(n)]
s[0] = w[0]
for i in range(1, n):
  s[i] = s[i-1]+w[i]
for i in range(n):
  ans = min(ans, abs((s[-1]-s[i])-s[i]))
print(ans)