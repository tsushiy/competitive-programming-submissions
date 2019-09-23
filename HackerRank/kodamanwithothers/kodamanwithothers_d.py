day, a, b, c, d = list(map(int, input().split()))
can_weekdays = [19*60, 22*60]
can_holiday = [7*60, 22*60]
s = a*60+b
t = c*60+d
if 1<=day<=5 and can_weekdays[0]<=s and t<=can_weekdays[1]:
  print("Yay!")
elif 6<=day<=7 and can_holiday[0]<=s and t<=can_holiday[1]:
  print("Yay!")
else:
  print(":(")