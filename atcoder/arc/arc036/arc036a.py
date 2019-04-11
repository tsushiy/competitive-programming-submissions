n, k = list(map(int, input().split()))
t = [int(input()) for i in range(n)]
for i in range(2, n):
  if t[i-2]+t[i-1]+t[i]<k:
    print(i+1)
    exit()
print(-1)