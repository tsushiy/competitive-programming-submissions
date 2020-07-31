import math
a, b, h, m = list(map(int, input().split()))
ar = 360 * ((h * 60 + m) / 720)
br = 360 * (m / 60)
r = min(abs(ar - br), 360 - abs(ar - br))
t = math.radians(r)
ans = a * a + b * b - 2 * a * b * math.cos(t)
ans = ans ** (1/2)
print(ans)