# sherif travells through car of 150 km/hr 
# bank robber travells 180 km/hr 5 miutes ahead of start 
# time to catch the robber ad distance they travelled at meet point

import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0,40,1000) # start ,finish , n points

ds = 2.5*t # distance travelled  by sherif from question
dr = 3 * (t-5) # by roberrer

fig,ax =plt.subplots()
plt.title('bank roberrer caught')
plt.xlabel('time')
plt.ylabel('distance')
ax.set_xlim([0,40])
ax.set_ylim([0,100])
ax.plot(t,ds,c='green')
ax.plot(t,dr,c='red')
plt.axvline(x=30,color='purple',linestyle = '--')
_ = plt.axhline(y=75,color='purple',linestyle = '--')
plt.show()