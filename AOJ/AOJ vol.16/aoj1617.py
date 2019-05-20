while True:
  s1 = input()
  if s1==".":
    break
  s2 = input()

  s1words = []
  s2words = []
  s1split = ""
  s2split = ""

  flag = False
  string = ""
  for e in s1:
    if not flag and e=='"':
      flag = True
      s1split += e
    elif flag and e=='"':
      flag = False
      s1split += e
      s1words.append(string)
      string = ""
    elif flag:
      string += e
    else:
      s1split += e

  flag = False
  string = ""
  for e in s2:
    if not flag and e=='"':
      flag = True
      s2split += e
    elif flag and e=='"':
      flag = False
      s2split += e
      s2words.append(string)
      string = ""
    elif flag:
      string += e
    else:
      s2split += e

  wrong = 0
  if len(s1words)!=len(s2words):
    print("DIFFERENT")
  else:
    for s, t in zip(s1words, s2words):
      if s!=t:
        wrong += 1
    if wrong==0 and s1split==s2split:
      print("IDENTICAL")
    elif wrong==1 and s1split==s2split:
      print("CLOSE")
    else:
      print("DIFFERENT")
