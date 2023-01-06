import random
from numpy import random
from cs50 import get_int

fromnumber = get_int("enter number from : ")

untilnumber = get_int("enter number until : ") + 1

repeat = get_int("repeat how many time : ")

destinynumber = get_int("what number result yo want : ")

stability = untilnumber - destinynumber
stabilfrom = destinynumber - stability

stability2 = destinynumber - fromnumber
stabilto = destinynumber + stability2



average = round((untilnumber - fromnumber) / 2)
average2 = round((untilnumber - fromnumber) / 6)
average3 = round(((untilnumber - fromnumber) / 6) * 5)

generate1 = fromnumber + average
generate2 = fromnumber + average2
generate3 = fromnumber + average3

print (generate1, generate2, generate3)

desirednumber = (destinynumber * repeat)

size=round((repeat - 1) / 2)
size2=((repeat - 1) - size)
size3=round((repeat - 1) / 4)
size4=((repeat - 1) - size3)

jumlah = 0

## result and output to array

while True:
    list1 = (random.randint(fromnumber, generate1, size))
    list2 = (random.randint(generate1, untilnumber, size2))
    minus = desirednumber - sum(list1)
    jumlah = (desirednumber - ((sum(list1) + sum(list2))))
    print (jumlah)
    while jumlah <= fromnumber:
        list1 = (random.randint(fromnumber, stabilto, size))
        list2 = (random.randint(fromnumber, stabilto, size2))
        jumlah = (desirednumber - ((sum(list1) + sum(list2))))
        print (list1)
        print (list2)
        print (jumlah)
    print (list1)
    print (list2)
    print (jumlah)
    while jumlah >= untilnumber:
        list1 = (random.randint(stabilfrom, untilnumber, size))
        list2 = (random.randint(stabilfrom, untilnumber, size2))
        jumlah = (desirednumber - ((sum(list1) + sum(list2))))
        print (list1)
        print (list2)
        print (jumlah)

    if jumlah <= destinynumber and jumlah >= fromnumber:
        break

## calculate the length of array


print (list1)
print (list2)
print (minus)
print (list1, list2)
print (desirednumber)
print (sum(list1) + sum(list2))
print (jumlah)

