a, b, k, l = list(map(int, input().split()))
print((k//l)*b+min(b, (k%l)*a))