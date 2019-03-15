a = input()
b = input()

def calc(r, l):
  idxr = 0
  idxrn = 0
  idxl = 0
  idxln = 0
  lb = 0

  for i, ele in enumerate(r):
    if ele=="(":
      lb+=1
    elif ele==")":
      lb-=1
    elif ele=="[" and lb==0:
      idxr = i+1
    elif ele=="]" and idxr >0:
      idxrn = i
      break

  for i, ele in enumerate(l):
    if ele=="(":
      lb+=1
    elif ele==")":
      lb-=1
    elif ele=="[" and lb==0:
      idxl = i+1
    elif ele=="]" and idxl>0:
      idxln = i
      break

  if idxr!=0 and idxl!=0:
    rr=r[1:idxr-2]
    rn=int(r[idxr:idxrn])
    rl=r[idxrn+2:-1]
    lr=l[1:idxl-2]
    ln=int(l[idxl:idxln])
    ll=l[idxln+2:-1]
    return "("+calc(rr, lr)+")["+str(rn+ln)+"]("+calc(rl, ll)+")"
  else:
    return ""

print(calc(a, b))
