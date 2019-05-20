n = int(input())
ab = [list(map(int, input().split())) for i in range(n)]
ab.sort(key=lambda x: x[1])
cur = 0
for a, b in ab:
  cur += a
  if cur>b:
    print("No")
    exit()
print("Yes")