import cs50

coin = 0
# get float
owe = cs50.get_float("Change owed: ")
while owe <= 0:
    owe = cs50.get_float("Change owed: ")

# change to cents
cents = round(owe * 100)

# loop by coins
while cents >= 25:
    cents = cents - 25
    coin += 1

while cents >= 10:
    cents = cents - 10
    coin += 1

while cents >= 5:
    cents = cents - 5
    coin += 1

while cents >= 1:
    cents = cents - 1
    coin += 1

print(f"cash {coin}")