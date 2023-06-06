import array as hash

def insert(size,table):
    key=int(input("Key= "))
    location=key%size

    if table[location]==-1:
        table[location]=key
        print("Key is Stored at Index",location)
    else:
        print("Which method you want to apply:\n1.Linear Probing\n2.Quadratic Probing")
        choice=int(input("Enter your Choice: "))

        if choice==1:
            linear_probing(table,location,key,size)
        else:
            quadratic_probing(table,location,key,size)

def linear_probing(table,location,key,size):
    for i in range(location+1,size):
        if table[i]==-1:
            table[i]=key
            return
            print("Collision is resolved by Linear Probing\n Key is stored at Index",i)
    for i in range(0,location):
        if table[i]==-1:
            table[i]=key
            return 
            print("Collision is resolved by Linear Probing\n Key is stored at Index",i)

def quadratic_probing(table,location,key,size):
    for i in range(1,size):
        new_location=(key+i*i)%size
        if table[new_location]==-1:
            table[new_location]=key
            break   
    print("Collision is resolved by Quadratic Probing\n Key is stored at Index",new_location)

def display(size,table):
    print("|",end=" ")
    for i in range(size):
        print(table[i],"|",end=" ")

def delete(size,table):
    del_key=int(input("Key to be Deleted= "))
    for i in range(size):
        if table[i]==del_key:
            table[i]=del_key
            table[i]=-1
            break
    print("Key is deleted\n")

def main():
    loop=True
    size=int(input("Size of hash table = "))
    table=hash.array('i',[-1]*size)
    print("Choose the Option")
    while loop:
        print("\n1.Insert\n2.Display\n3.Delete\n4.Exit")
        ch=int(input("Enter your Choice= "))
        if ch==1:
            insert(size,table)
        elif ch==2:
            display(size,table)
        elif ch==3:
            delete(size,table)
        elif ch==4:
            loop=False
main()
