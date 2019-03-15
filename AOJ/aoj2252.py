lset = ["q","w","e","r","t","a","s","d","f","g","z","x","c","v","b"]
rset = ["y","u","i","o","p","h","j","k","l","n","m"]

while True:
  s = input()
  ans = 0
  if s=="#":
    break
  else:
    for i in range(len(s)-1):
      if (s[i] in lset and s[i+1] in rset) or (s[i] in rset and s[i+1] in lset):
        ans+=1
      else:
        continue
  print(ans)
