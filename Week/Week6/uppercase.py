from cs50 import get_string

s = get_string("Before: ")
print("After: ", end="")
print(s.upper())

######

print("After: ", end="")
for c in s:
    print(c.upper(), end="")
print()

