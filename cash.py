from cs50 import get_float


# menanyakan berapa kembalian yg di punya

while True:
    kembalian = get_float("kembalian : ")
    if kembalian > 0:
        break

# dibulatkan
kembalian = round(kembalian * 100)

# nilai awal
hitung = 0
quarter = 0
dime = 0
nickel = 0
penny = 0

# ketika keadaan tercapai maka lakukan berulang kali
while kembalian >= 25:
    kembalian = kembalian - 25
    hitung += 1
    quarter += 1

while kembalian >= 10:
    kembalian = kembalian - 10
    hitung += 1
    dime += 1

while kembalian >= 5:
    kembalian = kembalian - 5
    hitung += 1
    nickel += 1

while kembalian >= 1:
    kembalian = kembalian - 1
    hitung += 1
    penny += 1


# menghitung berapa sisa kembalian jika ada
# menghitung berapa jumlah koin yg dipakai
# menghitung koin apa saja

print("kembalian", kembalian)
print("jumlah", hitung, "koin")
print(quarter, "quarter")
print(dime, "dime")
print(nickel, "nickel")
print(penny, "penny")
