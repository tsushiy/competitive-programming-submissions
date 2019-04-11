MOD = 10**9+7
s = input()

a = [0]*len(s)
c = [0]*len(s)
lq = [0]*len(s)
rq = [0]*len(s)

for i in range(1, len(s)):
  if s[i-1]=="A":
    a[i] = a[i-1]+1
  else:
    a[i] = a[i-1]
  if s[i-1]=="?":
    lq[i] = lq[i-1]+1
  else:
    lq[i] = lq[i-1]
for i in range(len(s)-2, -1, -1):
  if s[i+1]=="C":
    c[i] = c[i+1]+1
  else:
    c[i] = c[i+1]
  if s[i+1]=="?":
    rq[i] = rq[i+1]+1
  else:
    rq[i] = rq[i+1]

ans = 0
for i in range(1, len(s)-1):
  if s[i]=="B" or s[i]=="?":
    ans += int((3*a[i]+lq[i])*(3*c[i]+rq[i])*3**(lq[i]+rq[i]-2))%MOD
print(ans%MOD)