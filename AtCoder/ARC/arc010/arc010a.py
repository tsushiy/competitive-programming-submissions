n, m, a, b = list(map(int, input().split()))
for i in range(m):
  c = int(input())
  if n<=a:
    n+=b
  n-=c
  if n<0:
    print(i+1)
    exit()
print("complete")