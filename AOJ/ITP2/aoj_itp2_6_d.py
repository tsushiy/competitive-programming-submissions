from bisect import bisect_left, bisect_right
n = int(input())
a = list(map(int, input().split()))
q = int(input())
for i in range(q):
  k = int(input())
  print(bisect_left(a, k), bisect_right(a, k))