n = int(input())
a = [[[0]*10 for _ in range(3)] for _ in range(4)]
for i in range(n):
  b, f, r, v = list(map(int, input().split()))
  a[b-1][f-1][r-1] += v
for i in range(4):
  for j in range(3):
    print(" "+" ".join(map(str, a[i][j])))
  if i!=3:
    print("#"*20)