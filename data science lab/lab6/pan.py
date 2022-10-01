
from operator import index
import pandas as pd
import csv


l1=['Ram', 'sam', 'Prabhu']
l2=[9893893891, 9893893898, 9893893871]
l3=['SB','CA','SB']
l4=[959389389173,959389389179,959389389159]
l5=[8989839,7690990,989330]
d1={'Name': l1, 'Account_number': l2, 'Account_type': l3, 'Aadhar_no': l4, 'Balance':l5}
print(d1)

df1=pd.DataFrame(d1)
print(df1)


df1.to_csv('SBIAccountHolder.csv',index=False)

l1 =  ["Ram", "Sam", "Prabhu"]
l2 =  [959389389173, 959389389179, 959389389159]
l3 =  [8912347868, 1279287456, 4567389274]
l4 =  ["12-2-1990", "12-2-2000", "12-2-2010"]
l5 =  ["No 23, Kandigai, Chennai 127", "No 27, Melakottaiyur, Chennai 127", "No 43, Anna Nagar, Chennai 102"]
d2={'Name': l1, 'Aadhar_no': l2, 'contact': l3, 'DOB': l4, 'Address':l5}
print(d2)

df2=pd.DataFrame(d2)

# df2.to_csv('bank.csv',index=False)

		
  
while True:  
    print("MENU")  
    print("1. append record (row) of account holder")  
    print("2. delete record (row) of account holder")  
    print("3. credit")
    print("4. debit") 
    print("5. print details of account holder")
    print("6. create new csv file merging both")   
    print("7. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        SBIAccountHolder = dict()
        
        Name = input("Enter name of account holder :")
       
        Account_number = int(input("Enter account number  :"))
        
        Account_type = input("Enter type of account  :")

        Aadhar_no = int(input("Enter aadhar number of account holder :"))
        
        Balance = float(input("Enter balance :"))
        SBIAccountHolder[Account_number] = [Name,Account_type,Aadhar_no,Balance]
        
        
        field_names = ['Name','Account_number','Account_type','Aadhar_no','Balance']
        
        dict = {"Name": Name, "Account_number":Account_number,"Account_type":Account_type, "Aadhar_no":Aadhar_no, "Balance": Balance}
            
        with open('SBIAccountHolder.csv', 'a') as file:
            writer = csv.DictWriter(file,fieldnames=field_names)
        
            writer.writerow(dict)
 
    elif choice==2:
        
        df1 = pd.read_csv('SBIAccountHolder.csv', index_col="Account_number")
        accountnumber = int(input("Please enter account number to be deleted."))
        df1.drop([accountnumber],axis=0,inplace=True)
        df1.to_csv('SBIAccountHolder.csv')
        
        

    elif choice==3:
        df1 = pd.read_csv('SBIAccountHolder.csv', index_col="Account_number")
        print(df1)
        account_number = int(input("Please enter the  account number to be searched in which amount to be credited."))
        credit_amount = int(input("enter the amount to be credited "))
        df1.loc[account_number,'Balance'] += credit_amount
        df1.to_csv('SBIAccountHolder.csv')               
        
        
    elif choice==4:
        df1 = pd.read_csv('SBIAccountHolder.csv', index_col="Account_number")
        account_number = int(input("Please enter the  account number to be searched in which amount to be debited."))
        debit_amount = int(input("enter the amount to debited "))
        r = df1.loc[account_number,'Balance']
        c = df1.loc[account_number,'Account_type']
        if(c=="SB" and r-debit_amount<0):
           print("insufficent funds")
        else:
            df1.loc[account_number,'Balance'] -= debit_amount
            df1.to_csv('SBIAccountHolder.csv')
            print("amount debited successfully")
            
   
    elif choice==5:
        df1 = pd.read_csv('SBIAccountHolder.csv', index_col="Account_number")
        account_number = int(input("Please enter account number to be searched."))
        
        details = df1.loc[account_number]
        print(f'details of: {details}')
        
    elif choice==6:
        df2.to_csv('bank.csv',index=False)
        table1 = pd.read_csv('SBIAccountHolder.csv', index_col="Aadhar_no")
        table2 = pd.read_csv('bank.csv', index_col="Aadhar_no")
        table2 = table2.drop(["Name"], axis=1)
        table3 = pd.concat([table1, table2], axis=1).reindex(table1.index)
        table3.to_csv('finalfile.csv',index=False)
        print("\n-----Bank details merged with aadhar DB and saved to file -----\n")
        
    elif choice==7:
        break;   
    
    else:
        print("enter valid information")
        


