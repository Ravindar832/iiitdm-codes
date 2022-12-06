import pandas as pd

pf = pd.DataFrame({"Name":["S","B","N","K","L","S","P","Q","A","Q"],
                   "Roll":[1,2,3,4,5,6,7,8,9,10],
                   "CGPA":[8.8,9.0,7.6,7.7,7.3,8.5,6.4,6.6,7.8,9.5]})
print(pf)
pf["CGPA_Bin"] = pd.qcut(pf["CGPA"],q=5)  #pd.qcut
print(pf)
print(pf["CGPA_Bin"].value_counts())