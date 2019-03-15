n, a, b = list(map(int, input().split()))
print(min(5, n)*b+max(0, n-5)*a)