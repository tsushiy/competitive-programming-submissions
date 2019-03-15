m = int(input())
if m<100:
  v = 0
elif m<=5000:
  v = m//100
elif m<=30000:
  v = m//1000+50
elif m<=70000:
  v = (m//1000-30)//5+80
else:
  v = 89
print(str(v).zfill(2))