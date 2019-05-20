n = int(input())
v = list(map(int, input().split()))
v.sort()
cur = (v[0]+v[1])/2
for i in range(2, n):
  cur = (cur+v[i])/2
print(cur)