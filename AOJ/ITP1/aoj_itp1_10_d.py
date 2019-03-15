n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
d1, d2, d3, di = 0, 0, 0, 0
for i in range(n):
  d1 += abs(x[i]-y[i])
  d2 += (x[i]-y[i])**2
  d3 += abs((x[i]-y[i]))**3
  di = max(di, abs(x[i]-y[i]))
print(d1)
print(d2**0.5)
print(d3**(1/3))
print(di)