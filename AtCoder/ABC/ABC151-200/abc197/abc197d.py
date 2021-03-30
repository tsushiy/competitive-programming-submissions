import math

n = int(input())
x = complex(*map(int, input().split()))
y = complex(*map(int, input().split()))

c = (x + y) / 2
r = math.radians(360 / n)
ans = c + (x - c) * (math.cos(r) + math.sin(r) * 1j)
print(ans.real, ans.imag)
