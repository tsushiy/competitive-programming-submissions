n, a, b = list(map(int, input().split()))
t1 = min(a, b)
t2 = max(0, b-(n-a))
print(t1, t2)