q, h, s, d = list(map(int, input().split()))
n = int(input())
t1 = min(4*q, 2*h, s)
t2 = min(2*t1, d)
ans = t2*(n//2)
if n%2==1:
  ans += t1
print(ans)