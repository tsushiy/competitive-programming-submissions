from bisect import bisect_left, bisect_right
n = int(input())
a, b, c = [sorted(list(map(int, input().split()))) for i in range(3)]
ans = 0
for i in range(n):
  j = bisect_left(a, b[i])
  k = bisect_right(c, b[i])
  ans += j*(n-k)
print(ans)