k = int(input())
a, b = list(map(int, input().split()))
d = k - a % k
if (a % k != 0 and a + d > b):
  print("NG")
else:
  print("OK")