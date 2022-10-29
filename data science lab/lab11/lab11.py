# cs20b1085 gugulothu ravindar

import csv
import pandas as pd
import  matplotlib.pyplot as plt
from pyrsistent import v
from tables import Column
df1 = pd.read_csv("landslide_data3_miss.csv")
df2 = pd.read_csv("landslide_data3_original.csv")
# df1.drop('Outcome',axis=1 ,inplace=True)


while True:    
    print("1. Plot a graph of the attribute names (x-axis) with the number of missing values in them (y-axis). ")  
    print("2. Target attribute is “stationid”, Drop the tuples (rows) having missing values in the target attribute.  Print the total number of tuples deleted. ")  
    print("3. Delete (drop) the tuples (rows) having equal to or more than one third of attributes with missing values. Print the total number of tuples deleted.")
    print("4. After (b), count and print the number of missing values in each attributes. Also find and print the total number of missing values in the file (after the deletion of tuples). ") 
    print("5. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        print(df1.isnull().sum())
        df1.isnull().sum().plot(kind = 'bar')
        plt.show()
    elif choice==2:
        rows = len(df1.axes[0])
        # r2 = print(df1['stationid'].isnull().sum())
        new_data = df1.dropna(subset=['stationid'])
        rows1 = len(new_data.axes[0]) 
        r = rows-rows1
        print("number of tuples deleted = :",r)
    elif choice==3:
        rows = len(df1.axes[0])
        new_data = df1.dropna(thresh=len(df1.columns)-3)
        rows1 = len(new_data.axes[0]) 
        r = rows-rows1
        print("number of rows deleted = :",r)
    elif choice==4:
        rows = len(df1.axes[0])
        # r2 = print(df1['stationid'].isnull().sum())
        new_data = df1.dropna(subset=['stationid'])
        new_data1 = new_data.dropna(thresh=len(df1.columns)-3)
        rows1 = len(new_data1.axes[0]) 
        r = rows-rows1
        print(new_data1.isnull().sum())
        print("number of rows deleted = :",r)
    elif choice==5:
        break;   
    
    else:
        print("enter valid information")
        