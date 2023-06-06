set1=set()
n=int(input("Enter the number of elements to insert in set1:"))
for i in range(n):
    element=int(input("Enter the elements:"))
    set1.add(element)
set2=set()
n=int(input("Enter the number of elements to insert in set2:"))
for i in range(n):
    element=int(input("Enter the elements:"))
    set2.add(element)
print("Set A=",set1)
print("Set B=",set2)

def contains(set,element):
    return element in set

choice=1
while(choice!=0):
    print("1.Add\n2.Remove\n3.Contains\n4.\n5.Intersection\n6.Union\n7.Difference\n8.Subset\n9.Exit")
    choice=int(input("Enter your choice:"))
    if choice==1:
        x=int(input("Enter the element to insert in set A:"))
        set1.add(x)
        print("Updated Set A=",set1)
    elif choice==2:
        x=int(input("Enter the element to Remove in set A:"))
        set1.remove(x)
        print("Updated Set A=",set1)
    elif choice==3:
        x=int(input("Enter the element to check wheather it is present or not in set A:"))
        print(contains(set1,x))
    elif choice==4:
        #pending
        print()
    elif choice==5:
        print("Intersection=",set1.intersection(set2))
    elif choice==6:
        print("Union=",set1.union(set2))
    elif choice==7:
        print("Difference=",set1.difference(set2))#elements present in set A but not in set B
    elif choice==8:
        print("Subset=",set1.issubset(set2))#returns true if the elements of set A are present in Set B and False otherwise
    elif choice==9:
        exit()



