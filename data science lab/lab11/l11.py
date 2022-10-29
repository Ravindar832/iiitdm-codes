# cs20b1085 gugulothu ravindar

import csv
import pandas as pd
import numpy as np
import math
import  matplotlib.pyplot as plt
from pyrsistent import v
from tables import Column
df1 = pd.read_csv("landslide_data3_miss.csv")
df2 = pd.read_csv("landslide_data3_original.csv")

# print(df1.isnull().sum())
df1['stationid'] = df1['stationid'].fillna(df1['stationid'].mean())
df1['temperature'] = df1['temperature'].fillna(df1['temperature'].mean())
df1['humidity'] = df1['humidity'].fillna(df1['humidity'].mean())
df1['pressure'] = df1['pressure'].fillna(df1['pressure'].mean())
df1['rain'] = df1['rain'].fillna(df1['rain'].mean())
df1['lightavgw/o0'] = df1['lightavgw/o0'].fillna(df1['lightavgw/o0'].mean())
df1['lightmax'] = df1['lightmax'].fillna(df1['lightmax'].mean())
df1['moisture'] = df1['moisture'].fillna(df1['moisture'].mean())



while True:    
    print("1. mean")  
    print("2. median")  
    print("3. mode")
    print("4. standard deviation")
    print("5. Calculate the root mean square error (RMSE) between the original and replaced values for each attribute")
    print("6. Plot the RMSE with respect to the attributes")
    print("7. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        # print(df2.isnull().sum())
        m = df1.mean()
        print(m)
        n = df2.mean()
        print(n)
    elif choice==2:
        m = df1.median()
        print(m)
        n = df2.median()
        print(n)
    elif choice==3:
        m = df1.mode()
        print(m)
        n = df2.mode()
        print(n)
    elif choice==4:
        m = df1.std()
        print(m)
        n = df2.std()
        print(n)
    elif choice==5:
        m = df1['stationid']
        n = df2['stationid']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of stationid  : ",rsme)  
    
          
        m = df1['temperature']
        n = df2['temperature']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of temperature   : ",rsme)
        
        m = df1['humidity']
        n = df2['humidity']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of humidity   : ",rsme)
        
        m = df1['pressure']
        n = df2['pressure']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of pressure   : ",rsme)
        
        m = df1['rain']
        n = df2['rain']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of rain   : ",rsme)
        
        m = df1['lightavgw/o0']
        n = df2['lightavgw/o0']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of lightavgw/o0   : ",rsme)
        
        m = df1['lightmax']
        n = df2['lightmax']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of lightmax   : ",rsme)
        
        m = df1['moisture']
        n = df2['moisture']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of moisture   : ",rsme)  
        
        
    elif choice==6:
        m = df1['stationid']
        n = df2['stationid']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        # print("Root Mean Square Error of stationid  : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("stationid")
        plt.show()  
     
        m = df1['temperature']
        n = df2['temperature']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        # print("Root Mean Square Error of temperature   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("temperature")
        plt.show() 
        
        m = df1['humidity']
        n = df2['humidity']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of humidity   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("humidity")
        plt.show() 
        
        m = df1['pressure']
        n = df2['pressure']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of pressure   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("pressure")
        plt.show() 
        
        m = df1['rain']
        n = df2['rain']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of rain   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("rain")
        plt.show() 
        
        m = df1['lightavgw/o0']
        n = df2['lightavgw/o0']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of lightavgw/o0   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("lightavgw/o0")
        plt.show() 
        
        m = df1['lightmax']
        n = df2['lightmax']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of lightmax   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("lightmax")
        plt.show() 
        
        m = df1['moisture']
        n = df2['moisture']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of moisture   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("moisture")
        plt.show() 
    elif choice==7:
        break;   
    
    else:
        print("enter valid information")
    
        