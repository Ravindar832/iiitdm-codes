students = dict()
while True:  
    print("MENU")  
    print("1. insertion of details")  
    print("2. deletion of details")  
    print("3. search")    
    print("4. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
      
        n = int(input("Enter roll number of student :"))

        sname = input("Enter names of student :")
       
        cgpa = float(input("Enter cgpa :"))

        mobilenumber = int(input("enter mobile number:")) 
        students[n] = [sname,cgpa,mobilenumber]
        print("Dictionary of student created :")
        print(students)
    
    elif choice==2:
        r = int(input("Enter roll number of student to remove :"))
        students.pop(r)
        print(students)

    elif choice==3:
        s = int(input("Enter roll number of student to search :"))
        result = students.get(s)
        print(result)
    elif choice==4:
        break;
    
    else:
        print("enter valid information")

