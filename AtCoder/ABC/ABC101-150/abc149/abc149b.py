a, b, k = list(map(int, input().split()))
cnt = min(k, a)
a -= cnt
cnt = min(k-cnt, b)
b -= cnt
print(a, b)