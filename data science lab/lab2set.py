a = 0
while True:  
    print("MENU")
    print("1. create empty set")  
    print("2. insertion of set")  
    print("3. deletion of set")  
    print("4. search")
    print("5. print")
    print("6. union")
    print("7. intersection")
    print("8. set difference")
    print("9. symmetric difference")
    print("10. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        a = set()
        print('set a:',a)
    elif choice == 2:
        if a==0:
            print("set is not created")
        else:
            r = int(input("enter element to insert "))
            a.add(r)
            print(a)
    elif choice == 3:
        if a==0:
            print("set is not created")
        else:
            r = int(input("enter element to remove "))
            a.discard(r)
            print(a)    
    elif choice == 4:
        if a==0:
            print("set is not created")
        else:
            r = int(input("enter element to search "))
            x = r in a
            print(x)
    elif choice == 5:
        print(a)
    elif choice == 6:
         if a==0:
                print("set is not created")
         else:
            b = set()
            r = int(input("enter element to insert "))
            b.add(r)
            print(a,b)
            print(a | b)
    elif choice == 7:
        if a==0:
                print("set is not created")
        else:
            b = set()
            r = int(input("enter element to insert "))
            b.add(r)
            print(a,b)
            print(a & b)
    elif choice == 8:
        if a==0:
                print("set is not created")
        else:
            b = set()
            r = int(input("enter element to insert "))
            b.add(r)
            print(a,b)
            print(a - b)
            print(b - a)
    elif choice == 9:
        if a==0:
                print("set is not created")
        else:
            b = set()
            r = int(input("enter element to insert "))
            b.add(r)
            print(a,b)
            print(a ^ b)
    elif choice == 10:
        break;     
    else:
         print("enter valid number")
