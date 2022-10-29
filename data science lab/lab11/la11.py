# cs20b1085 gugulothu ravindar

import csv
import pandas as pd
import numpy as np
import math
import  matplotlib.pyplot as plt
from pyrsistent import v
from tables import Column
df3 = pd.read_csv("landslide_data3_miss.csv")
df2 = pd.read_csv("landslide_data3_original.csv")

# to interpolate the missing values
t = df3.interpolate(method='linear', limit_direction='forward', axis=0)

#t.interpolate(method ='linear', limit_direction='forward')
print(t.isnull().sum())

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
        m = t.mean()
        print(m)
        n = df2.mean()
        print(n)
    elif choice==2:
        m = t.median()
        print(m)
        n = df2.median()
        print(n)
    elif choice==3:
        m = t.mode()
        print(m)
        n = df2.mode()
        print(n)
    elif choice==4:
        m = t.std()
        print(m)
        n = df2.std()
        print(n)
    elif choice==5:
        m = t['stationid']
        n = df2['stationid']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of stationid  : ",rsme)  
    
          
        m = t['temperature']
        n = df2['temperature']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of temperature   : ",rsme)
        
        m = t['humidity']
        n = df2['humidity']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of humidity   : ",rsme)
        
        m = t['pressure']
        n = df2['pressure']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of pressure   : ",rsme)
        
        m = t['rain']
        n = df2['rain']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of rain   : ",rsme)
        
        m = t['lightavgw/o0']
        n = df2['lightavgw/o0']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of lightavgw/o0   : ",rsme)
        
        m = t['lightmax']
        n = df2['lightmax']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of lightmax   : ",rsme)
        
        m = t['moisture']
        n = df2['moisture']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        print("Root Mean Square Error of moisture   : ",rsme)  
        
        
    elif choice==6:
        m = t['stationid']
        n = df2['stationid']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        # print("Root Mean Square Error of stationid  : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("stationid")
        plt.show()  
     
        m = t['temperature']
        n = df2['temperature']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        # print("Root Mean Square Error of temperature   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("temperature")
        plt.show() 
        
        m = t['humidity']
        n = df2['humidity']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of humidity   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("humidity")
        plt.show() 
        
        m = t['pressure']
        n = df2['pressure']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of pressure   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("pressure")
        plt.show() 
        
        m = t['rain']
        n = df2['rain']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of rain   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("rain")
        plt.show() 
        
        m = t['lightavgw/o0']
        n = df2['lightavgw/o0']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of lightavgw/o0   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("lightavgw/o0")
        plt.show() 
        
        m = t['lightmax']
        n = df2['lightmax']
        MSE = np.square(np.subtract(m,n)).mean()   
        rsme = math.sqrt(MSE)  
        #print("Root Mean Square Error of lightmax   : ",rsme)
        fig, ax = plt.subplots(1, 1)
        ax.hist(rsme)
        ax.set_title("lightmax")
        plt.show() 
        
        m = t['moisture']
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
        