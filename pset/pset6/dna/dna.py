import sys
import csv

if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

people = []
STR = []

# open csv forst row to STR other to people
with open(sys.argv[1], "r") as file:
    reader = csv.reader(file)
    STR = next(reader)[1:]
    # for row in reader:
    #    people.append(row)

with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        people.append(row)

# open sequence txt
with open(sys.argv[2], "r") as file:
    reader = csv.reader(file)
    for row in reader:
        sequence = row[0]

# loop for max repeat
STR2 = []
for j in range(len(STR)):
    counter = [0] * len(sequence)
    for i in range(len(sequence) - len(STR[j]), -1, -1):
        if sequence[i: i + len(STR[j])] == STR[j]:
            if i + len(STR[j]) > len(sequence) - 1:
                counter[i] = 1
            else:
                counter[i] = 1 + counter[i + len(STR[j])]

    STR2.append(max(counter))

# loop people to found match

found = 0
for i in range(len(people)):
    match = 0
    for q in range(len(STR)):
        STRQ = STR2[q]
        PPLSTR = int(people[i][STR[q]])
        if STRQ == PPLSTR:
            if match < 1:
                match = 1
            else:
                match += 1
            if match == len(STR):
                found = people[i].get('name')

if found != 0:
    print(found)
else:
    print("No match")
