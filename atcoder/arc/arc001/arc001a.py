n = int(input())
c = input()
one, two, three, four = c.count("1"), c.count("2"), c.count("3"), c.count("4")
print(max(one, two, three, four), min(one, two, three, four))