n = int(input())
d = [int(input()) for i in range(n)]
s = sum(d)
m = max(d)
print(s)
print(max(0, 2*m-s))