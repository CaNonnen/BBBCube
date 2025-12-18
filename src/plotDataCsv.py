import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import numpy as np

fileName = "experiment_data20251213_181905.csv"
df = pd.read_csv("./ExperimentsData/"+fileName)
taille = len(df)
X = [i for i in range(taille)]


# temp = np.std(df["S1_mWx"])
# print(f"standart dev S1_mWx: {temp}")
# temp = np.mean(df["S1_mWx"])
# print(f"Mean S1_mWx: {temp}")

# temp = np.std(df["S1_mWy"])
# print(f"standart dev S1_mWy: {temp}")
# temp = np.mean(df["S1_mWy"])
# print(f"Mean S1_mWy: {temp}")

# temp = np.std(df["S2_mWx"])
# print(f"standart dev S2_mWx: {temp}")
# temp = np.mean(df["S2_mWx"])
# print(f"Mean S2_mWx: {temp}")

# temp = np.std(df["S2_mWy"])
# print(f"standart dev S2_mWy: {temp}")
# temp = np.mean(df["S2_mWy"])
# print(f"Mean S2_mWy: {temp}")
##
# temp = np.std(df["S1_mAx"])
# print(f"standart dev S1_mAx: {temp}")
# temp = np.mean(df["S1_mAx"])
# print(f"Mean S1_mAx: {temp}")

# temp = np.std(df["S1_mAy"])
# print(f"standart dev S1_mAy: {temp}")
# temp = np.mean(df["S1_mAy"])
# print(f"Mean S1_mAy: {temp}")

# temp = np.std(df["S2_mAx"])
# print(f"standart dev S2_mAx: {temp}")
# temp = np.mean(df["S2_mAx"])
# print(f"Mean S2_mAx: {temp}")

# temp = np.std(df["S2_mAy"])
# print(f"standart dev S2_mAy: {temp}")
# temp = np.mean(df["S2_mAy"])
# print(f"Mean S2_mAy: {temp}")

tempm1 = np.mean(df["S1_mWz"])
print(f"Mean S1_mWz: {tempm1}")
tempm2 = np.mean(df["S2_mWz"])
print(f"Mean S2_mWz: {tempm2}")



plt.figure(1)
sns.scatterplot(data=df,x=X,y="S1_mWx",label="S1_mWx")
sns.scatterplot(data=df,x=X,y="S1_mWy",label="S1_mWy")
sns.scatterplot(data=df,x=X,y="S2_mWx",label="S2_mWx")
sns.scatterplot(data=df,x=X,y="S2_mWy",label="S2_mWy")

plt.figure(2)
sns.scatterplot(data=df,x=X,y="S1_mAx",label="S1_mAx")
sns.scatterplot(data=df,x=X,y="S1_mAy",label="S1_mAy")
sns.scatterplot(data=df,x=X,y="S2_mAx",label="S2_mAx")
sns.scatterplot(data=df,x=X,y="S2_mAy",label="S2_mAy")

plt.figure(3)
sns.scatterplot(data=df,x=X,y="S1_mWz",label="S1_mWz")
sns.scatterplot(data=df,x=X,y="S2_mWz",label="S2_mWz")

plt.show()