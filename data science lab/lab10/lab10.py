# cs20b1085 gugulothu ravindar

import csv
import pandas as pd
import  matplotlib.pyplot as plt
from pyrsistent import v
from tables import Column
df1 = pd.read_csv("diabetes.csv")
df1.drop('Outcome',axis=1 ,inplace=True)
# m = df1.groupby(['Pregnancies']).mean()
# print(m)

while True:    
    print("1. mean")  
    print("2. median")  
    print("3. mode")
    print("4. mimimum ") 
    print("5. maximum")
    print("6. standard deviation")
    print("7. correlation coefficient for (Age) with all other attributes")
    print("8. correlation coefficient for (BMI) with all other attributes")
    print("9. scatter plot between  (Age) and each of the other attributes ")   
    print("10. scatter plot between  (BMI) and each of the other attributes ")
    print("11. Plot the histogram for the attributes Pregnancies and SkinThickness ")
    print("12. Plot the histogram for the attributes SkinThickness ")
    print("13. Plot the histogram of attribute Pregnancies and for each of the 2 Outcomes individually")
    print("14. Obtain the boxplot for all the attributes ")
    print("15. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        m = df1.mean()
        print(m)
    elif choice==2:
        m = df1.median()
        print(m)
    elif choice==3:
        m = df1.mode()
        print(m)
    elif choice==4:
        m = df1.min()
        print(m)
    elif choice==5:
        m = df1.max()
        print(m)
    elif choice==6:
        m = df1.std()
        print(m)
    elif choice==7:
        m = df1.corr()
        print(m['Age'])
    elif choice==8:
        m = df1.corr()
        print(m['BMI'])
    elif choice==9:
        m = df1.plot.scatter(x='Age', y='Pregnancies')
        m = df1.plot.scatter(x='Age', y='Glucose')
        m = df1.plot.scatter(x='Age', y='BloodPressure')
        m = df1.plot.scatter(x='Age', y='SkinThickness')
        m = df1.plot.scatter(x='Age', y='Insulin')
        m = df1.plot.scatter(x='Age', y='BMI')
        plt.show()      
    elif choice==10:
        m = df1.plot.scatter(x='BMI', y='Pregnancies')
        m = df1.plot.scatter(x='BMI', y='Glucose')
        m = df1.plot.scatter(x='BMI', y='BloodPressure')
        m = df1.plot.scatter(x='BMI', y='SkinThickness')
        m = df1.plot.scatter(x='BMI', y='Insulin')
        m = df1.plot.scatter(x='BMI', y='Age')
        plt.show()  
    elif choice==11:
        plt.hist(df1['Pregnancies'],  color='red')
        plt.show()
    elif choice==12:
        plt.hist(df1['SkinThickness'],  color='blue')
        plt.show()
    elif choice==13:
        df1 = pd.read_csv("diabetes.csv")
        m = df1.groupby(['Pregnancies', 'Outcome']).count()
        print(m)
        plt.hist(m)
        plt.show()
    elif choice==14:
        df1.boxplot(column='Pregnancies', return_type='axes')
        plt.show()
        df1.boxplot(column='Glucose', return_type='axes')
        plt.show()
        df1.boxplot(column='BloodPressure', return_type='axes')
        plt.show()
        df1.boxplot(column='SkinThickness', return_type='axes')
        plt.show()
        df1.boxplot(column='Insulin', return_type='axes')
        plt.show()
        df1.boxplot(column='BMI', return_type='axes')
        plt.show()
        df1.boxplot(column='Age', return_type='axes')
        plt.show()
    elif choice==15:
        break;   
    
    else:
        print("enter valid information")
        