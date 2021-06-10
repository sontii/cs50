from sys import argv

if len(argv) == 2:
    print(f"Your arg, {argv[1]}")
else:
    print("hello, world")

#######
# arg python argv.py hello

######

for arg in argv:
    print(arg)