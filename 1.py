size = int(input("Enter the table size :"))
n = int(input("\nEnter no. of records to be inserted :"))
hash_table = [-1] * size

def linear_probing(telephone_no):
    for i in range(size):
        index = (telephone_no + i) % size
        if hash_table[index] == -1:
            hash_table[index] = telephone_no
            print("\nRecord Inserted")
            return
    print("Table Full")

def Quadratic(telephone_no):
    for i in range(size):
        index = (telephone_no + i * i) % size
        if hash_table[index] == -1:
            hash_table[index] = telephone_no
            print("Record Inserted")
            return
    print("Element Cannot be inserted")

def search(telephone_no):
    count = 1
    for i in range(size):
        index = (telephone_no + i) % size
        if hash_table[index] == telephone_no:
            print("Element Found at index ", index)
            print("No.of comparisons =", count)
            return
        count += 1
    print("Record not found")

def display():
    print("Index Telephone number ")
    for i in range(size):
        if hash_table[i] != -1:
            print(i, "  ", hash_table[i])

while True:
    choice = int(input("\n1.Linear Probing\n2.Quadratic probing\n3.Search\n4.Display\n5.Exit\nChoice: "))
    if choice == 1:
        for _ in range(n):
            teleno = int(input("Enter telephone_no: "))
            linear_probing(teleno)
    elif choice == 2:
        for _ in range(n):
            teleno = int(input("Enter telephone_no: "))
            Quadratic(teleno)
    elif choice == 3:
        tele_num = int(input("Enter number to search: "))
        search(tele_num)
    elif choice == 4:
        display()
    elif choice == 5:
        break