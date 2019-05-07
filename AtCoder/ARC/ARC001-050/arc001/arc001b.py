a, b = list(map(int, input().split()))
ans = abs(b-a)//10
r = abs(b-a)%10
if r==0:
  pass
elif r in (1, 5):
  ans += 1
elif r in (2, 4, 6, 9):
  ans += 2
elif r in (3, 7, 8):
  ans += 3
print(ans)