m, n, N = list(map(int, input().split()))
ans = N
while True:
  if N<m:
    break
  ans += (N//m)*n
  N = N%m+(N//m)*n
print(ans)