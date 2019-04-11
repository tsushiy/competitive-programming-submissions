a, b, x = map(int, input().split())
ans = (b//x+1) -((a-1)//x+1)
print(ans)