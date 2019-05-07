a, b = map(int, input().split())
s = 0
for i in range(1, b-a):
  s+=i
print(s-a)