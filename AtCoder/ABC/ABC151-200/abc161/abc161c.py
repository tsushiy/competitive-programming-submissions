n, k = list(map(int, input().split()))
ans = n
ans = min(ans, n%k)
ans = min(ans, abs(k-(n%k)))
print(ans)