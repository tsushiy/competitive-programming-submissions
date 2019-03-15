while True:
  n = int(input())
  if n == 0:
    break
  else:
    codelist=[]
    endflag=0
    for i in range(n):
      s = input()
      code=s[0]
      for j in range(len(s)-1):
        if s[j] in {"a","i","u","e","o"}:
          code+=s[j+1]

      codelist.append(code)

    maxlen=0
    for ele in codelist:
      maxlen = max(maxlen, len(ele))

    for i in range(len(codelist)):
      if len(codelist[i])<maxlen:
        for _ in range(maxlen-len(codelist[i])):
          codelist[i]+="_"

    for i in range(1, maxlen+1):
      prelist = [codelist[j][:i] for j in range(len(codelist))]
      preset = set(prelist)
      if len(preset) == len(codelist):
        print(i)
        endflag=1
        break

    if endflag !=1:
      print(-1)
