
from mimetypes import init

import pandas as pd

class student:
    def _init_(self,file_name):
        self.file_name = "students.csv"
        table = pd.DataFrame({
        "roll_num":[0],
		"sName": ["names"],
        "math_mark":[0],
        "physics_mark":[0],
        "chemistry_mark":[0],
        "assignment_mark":[0],
        "totalmarkl_mark":[0],
		"Grade":["grades"]
		})
        table.to_csv(self.file_name, index=False)
        
    def appendRecord(self,file_name):
        table = pd.read_csv(self.file_name)
        print("\n-----Welcome to studet Creation-----\n")
        rollnum = int(input("Enter roll number of student :"))
        sname = input("Enter names of student :")
       
        mathmark = int(input("Enter maths mark :"))
        
        physicsmark = int(input("Enter physics mark :"))
        
        chemistrymark = int(input("Enter chemistry mark :"))
        
        assigmentmark = int(input("Enter assignment mark :"))
        totalmark = mathmark+physicsmark+chemistrymark+assigmentmark
   
        if(totalmark>=85):
            grade = 'A'
        elif(totalmark<85 and totalmark>=65):
            grade = 'B'
        elif(totalmark<65 and totalmark>=50):
            grade = 'c'
        elif(totalmark<50 and totalmark>=35):
            grade = 'd'
        else:
            grade = 'fail'
        details = [rollnum, sname, mathmark, physicsmark, chemistrymark, assigmentmark,totalmark,grade]
        table.loc[len(table.index)] = details
        table.to_csv(self.file_name, index=False)
        print("\n-----Your student created successfully-----\n")

    def deleteRecord(self):
        table = pd.read_csv(self.file_name, index_col=["studentNumber"])
        print("\n-----Welcome to student Deletion-----\n")
        studetNumber = int(input("Please roll to delete number: "))
        try:
            table.drop([studetNumber], inplace=True, axis=0)
            table.to_csv(self.file_name)
            print("\n-----Your student details deleted successfully-----\n")
        except:
            print("roll number does not exist.")

	
    def details(self):
        table = pd.read_csv(self.file_name, index_col=["studentNumber"])
        print("\n-----Welcome to student Details-----\n")
        studentNumber = int(input("Please enter roll number  student : "))
        try:
            details = table.loc[studentNumber]
            print(f'details of: {details}')
		
        except:
            print("student number does not exist")

students = student()
	
choice = 1
while(choice!=4):
    print("1. Append record(row) of a student Holder")
    print("2. Delete record(row) given student Number")
    print("3. Print student details given student Number")
    print("4. Exit")
    choice = int(input("Enter your choice: "))
    if(choice == 1):
        students.appendRecord()
        
        
    elif(choice == 2):
        students.deleteRecord()
    
    elif(choice == 3):
        students.details()
	
    elif(choice == 4):
     print("\n-----student Editing is ended by the user-----\n")
     continue
    else:
        print("Please enter a valid choice")
	

