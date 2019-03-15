n = int(input())
ans = 0
for i in range(1, n+1):
  ans += 10000*i/n
print(int(ans))