n = int(input())
a = list(map(int, input().split()))
if n%2:
  b = [i for i in range(n-1, 0, -2)]*2
  b.append(0)
else:
  b = [i for i in range(n-1, 0, -2)]*2
if sorted(a)!=sorted(b):
  print(0)
else:
  print(pow(2, n//2, 10**9+7))