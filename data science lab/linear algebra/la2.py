# jill designs a solar panel 
# on april 1st mark1 generates power 1kj/per day
# on may 1st mark2 generates power 4kj/per day

# So to follow 
# Amount(Mark 1) =(T+30)* 1 ( Where T unit day)
# Amount(Mark 2) = T*4 

# So when both two amounts are equal 
# (T+30) *1 = T*4
# T+30 = 4T
# 30 = 4T-T
# 30 = 3T
# T=10

# so after 10 days both amount should be equal which is on May 10th
# and the total amount will be generated is 
# (10+30) + 4*10 = 80 kj

import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0,40,1000) # start ,finish , n points

m1 = 1*t # m1
m2 = 4 * (t-30) # m2

fig,ax =plt.subplots()
plt.title('solar panel power')
plt.xlabel('time')
plt.ylabel('amount')
ax.set_xlim([0,80])
ax.set_ylim([0,100])
ax.plot(t,m1,c='green')
ax.plot(t,m2,c='red')
plt.axvline(x=40,color='purple',linestyle = '--')
_ = plt.axhline(y=40,color='purple',linestyle = '--')
plt.show()