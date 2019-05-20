n, k, q = list(map(int, input().split()))
ans = [0]*n
for i in range(q):
  a = int(input())
  a -= 1
  ans[a] += 1
for i in range(n):
  ans[i] = k - q + ans[i]
  if ans[i]>0:
    print("Yes")
  else:
    print("No")