# cs20b1085 gugulothu ravindar

import numpy as np
import matplotlib.pyplot as plt

random_sizes = [1,2,4,8,16,32]

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
        m = 1000
        expo_dist = np.random.exponential(size = m, scale = 1.0)
        expo_dist = np.array([round(x, 2) for x in expo_dist])
        print("generate exponnential of random data of size m ")
        print(expo_dist)
    elif choice==2:
        m = 1000
        unif_dist = np.random.uniform(0,2, size = m )
        unif_dist = np.array([round(x, 2) for x in unif_dist])
        print("generate uniform distribution of random data of size m ")
        print(unif_dist)
    elif choice==3:
        m = 1000
        bernoulli_dist = np.random.binomial(1,0.5, size = m )
        bernoulli_dist = np.array([round(x, 2) for x in bernoulli_dist])
        print("generate bernoulli distribution of random data of size m ")
        print(bernoulli_dist)    
    elif choice==4:
        random_sizes = [1,2,4,8,16,32]
        sample_expo_mean = []
        for i in random_sizes:
            expo_dist = np.random.exponential(size=i,scale=1.0)
            expo_dist = np.array([round(x,2)for x in expo_dist])
            sum_expo = 0
            for x in expo_dist:
                sum_expo += x
            mean_expo = sum_expo/1000
            sum_expo = 0
            for x in expo_dist:
                sum_expo += (x - mean_expo)**2
            std_expo = (sum_expo/1000)**(1/2)
            s = np.mean(expo_dist)
            sample_expo_mean.append(s)
        normals = [(x - mean_expo)/(std_expo/(1000**1/2)) for x in sample_expo_mean]
        plt.plot(sample_expo_mean,normals)
        plt.xlabel("sample mean")
        plt.ylabel("normal distribution")
        plt.title("Plot for Exponential Distribution in central limit theorem ")
        plt.show()
        
    elif choice==5:
        random_sizes = [1,2,4,8,16,32]
        sample_unif_mean = []
        for i in random_sizes:
            unif_dist = np.random.uniform(0,2,size=i)
            unif_dist = np.array([round(x,2)for x in unif_dist])
            sum_unif = 0
            for x in unif_dist:
                sum_unif += x
            mean_unif = sum_unif/1000
            sum_unif = 0
            for x in unif_dist:
                sum_unif += (x - mean_unif)**2
            std_unif = (sum_unif/1000)**(1/2)
            s = np.mean(unif_dist)
            sample_unif_mean.append(s)
        normals = [(x - mean_unif)/(std_unif/(1000**1/2)) for x in sample_unif_mean]
        plt.plot(sample_unif_mean,normals)
        plt.xlabel("sample mean")
        plt.ylabel("normal distribution")
        plt.title("Plot for uniform Distribution in central limit theorem ")
        plt.show()
        
    elif choice==6:
        random_sizes = [1,2,4,8,16,32]
        sample_bernoulli_mean = []
        for i in random_sizes:
            bernoulli_dist = np.random.binomial(1,0.5,size=i)
            bernoulli_dist = np.array([round(x,2)for x in bernoulli_dist])
            sum_bernoulli = 0
            for x in bernoulli_dist:
                sum_bernoulli += x
            mean_bernoulli = sum_bernoulli/1000
            sum_bernoulli = 0
            for x in bernoulli_dist:
                sum_bernoulli += (x - mean_bernoulli)**2
            std_bernoulli = (sum_bernoulli/1000)**(1/2)
            s = np.mean(bernoulli_dist)
            sample_bernoulli_mean.append(s)
        normals = [(x - mean_bernoulli)/(std_bernoulli/(1000**1/2)) for x in sample_bernoulli_mean]
        plt.plot(sample_bernoulli_mean,normals)
        plt.xlabel("sample mean")
        plt.ylabel("normal distribution")
        plt.title("Plot for bernoulli Distribution in central limit theorem ")
        plt.show()
         
    elif choice==7:
        break;   
     
    else:
        print("enter valid information")
        