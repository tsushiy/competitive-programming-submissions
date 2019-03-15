sa = input()
sb = input()
sc = input()

t=sa[0]
sa=sa[1:]
while True:
  if t=="a":
    if len(sa)==0:
      print("A")
      exit()
    t=sa[0]
    sa=sa[1:]
  elif t=="b":
    if len(sb)==0:
      print("B")
      exit()
    t=sb[0]
    sb=sb[1:]
  else:
    if len(sc)==0:
      print("C")
      exit()
    t=sc[0]
    sc=sc[1:]