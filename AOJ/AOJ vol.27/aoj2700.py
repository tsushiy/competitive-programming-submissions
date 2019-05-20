while True:
  n = int(input())
  if n==0:
    break

  s = []
  maxlen = 0
  for i in range(n):
    st = input()
    stt = ""
    for j in range(len(st)):
      if j==0 or st[j-1] in "aiueo":
        stt += st[j]
    s.append(stt)
    maxlen = max(maxlen, len(stt))
  ans = -1
  k = 1
  while k<=maxlen:
    code = set()
    for e in s:
      code.add(e[:k])
    if len(code)==len(s):
      ans = k
      break
    k += 1
  print(ans)