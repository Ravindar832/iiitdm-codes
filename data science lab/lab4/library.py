import pickle
import os
pfile = open('library.txt', 'ab')
pfile.close()


while True:  
    print("MENU")  
    print("1. write details")  
    print("2. read details")  
    print("3. search")    
    print("4. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:

        pfile = open('library.txt', 'ab')
      
        issn = int(input("Enter serial number of book :"))

        bname = input("Enter name of book :")
       
        price = float(input("Enter price :"))

        edition = int(input("Enter edition of book :"))

        year = int(input("Enter year of book  published :"))

        author_name = input("Enter author name of book :")

        
        
        n = [issn,bname,price,edition,year,author_name]

        pickle.dump(n,pfile)
        pfile.close()

        print(n)
    
    elif choice==2:
        pfile=open('library.txt', 'rb')
        while(1):
            try:
                n=pickle.load(pfile)
                print(n)
            except  EOFError:
             print('End of the file')
             break    
        pfile.close()
        

    elif choice==3:
        print("enter the booknname to search")
        bname=input()
        pfile=open('library.txt', 'rb')
        while(1):
            try:
             x=pickle.load(pfile)
             if(x[1]==bname):
                 print("book found!!")
                 print(x)
                 break
             
            except  EOFError:
             print('book is not found')
             break    
        pfile.close()
        
    elif choice==4:
        os.remove('library.txt')
        break;   
    
    else:
        print("enter valid information")