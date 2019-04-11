n = int(input())
j = n
p = []
for i in range(1, int(n**0.5)+1):
  if n%i==0:
    p.append((i, n//i))
a, b = p[-1][0], p[-1][1]
print(max(len(str(a)), len(str(b))))