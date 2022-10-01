# cs20b1085 gugulothu ravindar

import csv
import pandas as pd

df1 = pd.read_csv("diabetes.csv")
df1.drop('Type',axis=1 ,inplace=True)
# print(df1)

while True:  
    print("MENU")  
    print("1. probability of diabetes Age above 50")  
    print("2. probability of diabetes Age between 40 and 50")  
    print("3. probability of diabetes Age between 30 and 40")
    print("4. probability of diabetes Age less than 30") 
    print("5. probability of diabetes  glucose level of more than 120 + blood pressure of more than 90 + skin thickness of more than 30 + insulin above 150 + BMI above 25.")   
    print("6. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        num_of_people = len(df1[df1['Age'] > 50].values) 
        print("number of people with age above 50 :" ,num_of_people )
        num_of_diabetes = len(df1[(df1['Age'] > 50)&(df1["Outcome"] == 1)].values)
        print("number of people with diabetes with age above 50 :" ,num_of_diabetes)
        probability = num_of_diabetes/num_of_people
        print("probability = ",probability)

    elif choice==2:
        num_of_people = len(df1[(df1['Age'] > 40)&(df1['Age'] <=50)].values)
        print("number of people with age above 40 and less than or equal to 50 :" ,num_of_people )
        num_of_diabetes = len(df1[((df1['Age'] > 40)&(df1['Age'] <=50))&(df1["Outcome"] == 1)].values)
        print("number of people with diabetes with age above 40 and less than or equal to 50 :" ,num_of_diabetes)
        probability = num_of_diabetes/num_of_people
        print("probability = ",probability)
        
        

    elif choice==3:
        num_of_people = len(df1[(df1['Age'] > 30)&(df1['Age'] <=40)].values)
        print("number of people with age above 30 and less than or equal to 40 :" ,num_of_people )
        num_of_diabetes = len(df1[((df1['Age'] > 30)&(df1['Age'] <=40))&(df1["Outcome"] == 1)].values)
        print("number of people with diabetes with age above 30 and less than or equal to 40 :" ,num_of_diabetes)
        probability = num_of_diabetes/num_of_people
        print("probability = ",probability)
        
                      
        
        
    elif choice==4:
        num_of_people = len(df1[df1['Age'] <= 30].values) 
        print("number of people with age less than or equal 30 :" ,num_of_people )
        num_of_diabetes = len(df1[(df1['Age'] <= 30)&(df1["Outcome"] == 1)].values)
        print("number of people with diabetes with age less than or equal 30 :" ,num_of_diabetes)
        probability = num_of_diabetes/num_of_people
        print("probability = ",probability)
       
            
   
    elif choice==5:
        num_of_people = len(df1[(df1['Glucose'] > 120)&(df1['BloodPressure'] > 90)&(df1['SkinThickness'] > 30)&(df1['Insulin'] > 150)&(df1['BMI'] > 25)].values)
        print("num of people with glucose level of more than 120 + blood pressure of more than 90 + skin thickness of more than 30 + insulin above 150 + BMI above 25 : ",num_of_people)
        num_of_diabetes = len(df1[(df1['Glucose'] > 120)&(df1['BloodPressure'] > 90)&(df1['SkinThickness'] > 30)&(df1['Insulin'] > 150)&(df1['BMI'] > 25)&(df1["Outcome"] == 1)].values)
        print("num of diabetes people with glucose level of more than 120 + blood pressure of more than 90 + skin thickness of more than 30 + insulin above 150 + BMI above 25 : ",num_of_diabetes)
        probability = num_of_diabetes/num_of_people
        print("probability = ",probability)
        
         
    elif choice==6:
        break;   
    
    else:
        print("enter valid information")
        