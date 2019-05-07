class Dice:
  def __init__(self, top=1, front=2, left=4, right=3, back=5, bottom=6):
    self.d = {"TOP":top, "FRONT":front, "LEFT":left, "RIGHT":right, "BACK":back, "BOTTOM":bottom}

  def roll_x(self):
    self._roll("TOP", "FRONT", "BOTTOM", "BACK")
  
  def roll_y(self):
    self._roll("FRONT", "LEFT", "BACK", "RIGHT")
  
  def roll_z(self):
    self._roll("TOP", "LEFT", "BOTTOM", "RIGHT")
  
  def _roll(self, a, b, c, d):
    self.d[a], self.d[b], self.d[c], self.d[d] = \
    self.d[b], self.d[c], self.d[d], self.d[a]

  def all_rolls(self):
    ret = []
    for i in range(6):
      if i%2:
        self.roll_x()
      else:
        self.roll_y()
      for _ in range(4):
        self.roll_z()
        t = self.d.copy()
        ret.append(t)
    return ret

d = list(map(int, input().split()))
dd = Dice(d[0], d[1], d[3], d[2], d[4], d[5])
l = dd.all_rolls()
q = int(input())
for i in range(q):
  t, f = list(map(int, input().split()))
  for ele in l:
    if ele["TOP"]==t and ele["FRONT"]==f:
      print(ele["RIGHT"])
      break