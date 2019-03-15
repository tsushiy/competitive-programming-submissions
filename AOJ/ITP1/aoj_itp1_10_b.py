a, b, c = list(map(int, input().split()))
from math import pi, sin, cos
print(a*b*0.5*sin(c*pi/180))
print(a+b+(a**2+b**2-2*a*b*cos(c*pi/180))**0.5)
print(b*sin(c*pi/180))