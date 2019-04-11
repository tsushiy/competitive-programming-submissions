n, k = map(int, input().split())
d = set(input().split())
ans = 10000
for i in range(n, n*10):
  if set(str(i)) & d == set():
    ans=i
    break
print(ans)