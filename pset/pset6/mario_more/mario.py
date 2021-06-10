from cs50 import get_int

height = get_int("Height: ")
while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    # loop for left pyramid
    for j in range(height):
        if i + j >= height - 1:
            print("#", end="")
        else:
            print(" ", end="")
    
    # print gap
    print("  ", end="")
    
    # loop for right pyramid
    for j in range(i + 1):
        print("#", end="")
        
    print()