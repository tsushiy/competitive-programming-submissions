MAX = 55555
p = [1]*(MAX+1)
p[0], p[1] = 0, 0
pp = []

for i in range(2, MAX, 2):
  p[i] = 0

for i in range(3, int(MAX**0.5)+1, 2):
  if p[i]:
    for j in range(i*2, MAX, i):
      p[j] = 0

for i in range(MAX+1):
  if p[i] and i%5==1:
    pp.append(i)

n = int(input())
print(" ".join(map(str, pp[:n])))