while True:
  st = list(input().split("/"))
  if st == ["#"]:
    break
  a, b, c, d = map(int, input().split())

  s=[]
  for i in range(len(st)):
    stt=[]
    for ele in st[i]:
      if ele=="b":
        stt.append("b")
      else:
        for _ in range(int(ele)):
          stt.append(".")
    s.append(stt)

  s[a-1][b-1] = "."
  s[c-1][d-1] = "b"

  ans_ = []
  for i in range(len(s)):
    sr = ""
    c = 0
    for j in range(len(s[i])):
      if s[i][j] == 'b':
        if c != 0:
          sr += "{}".format(c)
        sr += "b"
        c=0
      elif s[i][j] == '.':
        c += 1
    if c!=0:
      sr+="{}".format(c)
    ans_.append(sr)
  ans = "/".join(ans_)
  print(ans[:])
