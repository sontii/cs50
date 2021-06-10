from cs50 import get_string

s = get_string("Do you agree? ")

if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")


if s.lower() in ["y", "Yes"]:
    print("Agreed.")
elif s.lower() in ["n", "no"]:
    print("Not agreed.")