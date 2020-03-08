n, a, b = list(map(int, input().split()))
x = n//(a+b)
rem = n - (a+b)*x
ans = a * x + min(a, rem)
print(ans)