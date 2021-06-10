import cs50

cardN = 0
n = 0
# get float
cardN = cs50.get_int("Number: ")
while cardN <= 0:
    cardN = cs50.get_int("Number: ")

# store cardnumber
n = cardN

# variables
counter = 0
csum = 0
allsum = 0
firstdigit = 0

while n > 1:
    csum = n % 10
    allsum = csum + allsum

    if n > 0:
        counter += 1

    n = n // 10

    # store first digit
    if n > 10:
        firstdigit = n

    # last digit -1
    csum = (n % 10) * 2
    if csum > 9:
        csum = csum - 9

    allsum = csum + allsum

    # counter
    if n > 0:
        counter += 1

    n = n // 10
    if n > 10:
        firstdigit = n

if firstdigit == 34 or firstdigit == 37 or counter == 15:
    print("AMEX")
elif (firstdigit > 39 and firstdigit < 50) and (counter == 13 or counter == 16):
    print("VISA")
elif (firstdigit > 50 and firstdigit < 56) and counter == 16:
    print("MASTERCARD")
else:
    print("INVALID")