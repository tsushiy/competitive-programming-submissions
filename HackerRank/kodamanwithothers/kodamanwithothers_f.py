n, k = list(map(int, input().split()))
abc = [None]*n
for i in range(n):
  a, b = list(map(int, input().split()))
  abc[i] = (a, b, a-b)
abc.sort(key=lambda x: x[2], reverse=True)
ans = 0
for i in range(n):
  if i < k:
    ans += abc[i][1]
  else:
    ans += abc[i][0]
print(ans)