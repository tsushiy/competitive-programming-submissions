n = int(input())
a = [0 for i in range(1450)]
for i in range(n):
  s, t = map(int, input().split("-"))
  s = s-s%5
  t = (t+5)-t%5 if t%5!=0 else t
  s = s//100*60+s%100
  t = t//100*60+t%100
  a[s+1] += 1
  a[t+1] -= 1
for i in range(1, 1450):
  a[i] += a[i-1]

ans = []
for i in range(1, 1450):
  if a[i]>0 and a[i-1]==0:
    start = "{:04}".format((i-1)//60*100+(i-1)%60)
  elif a[i]==0 and a[i-1]>0:
    end = "{:04}".format((i-1)//60*100+(i-1)%60)
    ans.append("-".join([start, end]))
for e in ans:
  print(e)