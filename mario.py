
# import get int dari cs50
from cs50 import get_int

# loop always when not true the needed integer and range, if false then break
while True:
    height = get_int("Height : ")
    if height < 9 and height > 0:
        break

# look for in range (start from, the value needed, how much step)
for i in range(0, height, 1):
    for j in range(0, height, 1):
        if i + j < height - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()