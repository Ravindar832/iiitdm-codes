# cs20b1085 gugulothu ravindar

import numpy as np
import matplotlib.pyplot as plt

random_sizes = [10, 100, 500, 1000, 5000, 10000, 50000]

while True:  
    print("MENU")  
    print("1. Exponential Distribution ")  
    print("2. Uniform Distribution (self-study) ")  
    print("3. Bernoulli Distribution")
    print("4. plot sample mean for exponential distribution ")
    print("5. plot sample mean for uniform distribution")
    print("6. plot sample mean for bernoulli distribution")
    print("7. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        m = 50
        expo_dist = np.random.exponential(size = m, scale = 1.0)
        expo_dist = np.array([round(x, 2) for x in expo_dist])
        print("generate exponnential of random data of size m ")
        print(expo_dist)
    elif choice==2:
        m = 50
        unif_dist = np.random.uniform(0,2, size = m )
        unif_dist = np.array([round(x, 2) for x in unif_dist])
        print("generate uniform distribution of random data of size m ")
        print(unif_dist)
    elif choice==3:
        m = 50
        bernoulli_dist = np.random.binomial(1,0.5, size = m )
        bernoulli_dist = np.array([round(x, 2) for x in bernoulli_dist])
        print("generate bernoulli distribution of random data of size m ")
        print(bernoulli_dist)    
    elif choice==4:
        random_sizes = [10,100,500,1000,5000,10000,50000]
        sample_expo_mean = []
        for i in random_sizes:
            expo_dist = np.random.exponential(size=i,scale=1.0)
            expo_dist = np.array([round(x,2)for x in expo_dist])
            s = np.mean(expo_dist)
            sample_expo_mean.append(s)
        plt.plot(random_sizes,sample_expo_mean)
        plt.xlabel("sample Size")
        plt.ylabel("sample Mean")
        plt.title("Plot for sample mean Exponential Distribution")
        plt.show()
        
    elif choice==5:
        random_sizes = [10,100,500,1000,5000,10000,50000]
        sample_unif_mean = []
        for i in random_sizes:
            unif_dist = np.random.uniform(0,2, size=i)
            unif_dist = np.array([round(x,2)for x in unif_dist])
            s = np.mean(unif_dist)
            sample_unif_mean.append(s)
        plt.plot(random_sizes,sample_unif_mean)
        plt.xlabel("sample Size")
        plt.ylabel("sample Mean")
        plt.title("Plot for sample mean uniform Distribution")
        plt.show()
        
    elif choice==6:
        random_sizes = [10,100,500,1000,5000,10000,50000]
        sample_bernoulli_mean = []
        for i in random_sizes:
            bernoulli_dist = np.random.binomial(1,0.5,size=i)
            bernoulli_dist = np.array([round(x,2)for x in bernoulli_dist])
            s = np.mean(bernoulli_dist)
            sample_bernoulli_mean.append(s)
        plt.plot(random_sizes,sample_bernoulli_mean)
        plt.xlabel("sample Size")
        plt.ylabel("sample Mean")
        plt.title("Plot for sample bernoulli Distribution")
        plt.show() 
    elif choice==7:
        break;   
     
    else:
        print("enter valid information")
        