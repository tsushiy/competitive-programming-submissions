a, b, c = map(int, input().split())
k = int(input())
ans = a+b+c+max(a, b, c)*2**k-max(a, b, c)
print(ans)