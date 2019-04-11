w, h = list(map(int, input().split()))
def solve(a, b):
  ret = float("INF")
  for i in range(a):
    s1 = b*i
    s2 = (b//2)*(a-i)
    s3 = (b-b//2)*(a-i)
    ret = min(ret, max(s1, s2, s3)-min(s1, s2, s3))
    s2 = b*((a-i)//2)
    s3 = b*((a-i)-(a-i)//2)
    ret = min(ret, max(s1, s2, s3)-min(s1, s2, s3))
  return ret
print(min(solve(w, h), solve(h, w)))