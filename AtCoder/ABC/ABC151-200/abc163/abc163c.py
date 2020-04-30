n = int(input())
a = list(map(int, input().split()))
b = [0 for i in range(n)]
for e in a:
  b[e-1] += 1
for e in b:
  print(e)