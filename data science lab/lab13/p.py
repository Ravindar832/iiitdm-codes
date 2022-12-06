# cs20b1085 gugulothu ravindar

import csv
import pandas as pd
import numpy as np

df1 = pd.read_csv("SteelPlateFaults-2class.csv")
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.cluster import KMeans, k_means
from sklearn.metrics import accuracy_score
from sklearn import datasets
from sklearn.metrics import confusion_matrix
import matplotlib.pyplot as plt
from sklearn.metrics import classification_report
from sklearn.metrics import plot_confusion_matrix
from sklearn import metrics
from sklearn import preprocessing


# print(df1.keys())

while True:  
    print("MENU")  
    print("1.  confusion matrix  and classification accuracy for K = 1.")  
    print("2.  confusion matrix  and classification accuracy for K = 3.")  
    print("3.  confusion matrix  and classification accuracy for K = 5.")
    print("4.  normalized data confusion matrix  and classification accuracy for K = 1.") 
    print("5.  normalized data confusion matrix  and classification accuracy for K = 3.") 
    print("6.  normalized data confusion matrix  and classification accuracy for K = 5.")  
    print("7.  Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        featuresList=["X_Minimum", "X_Maximum", "Y_Minimum","X_Perimeter"]
        X = df1[featuresList].to_numpy() # choosing features from features list
        Y = df1["Class"].to_numpy() # choosing type of steel  as the labels
        #splitting  features and labels as train and test set 70, 30% respectively
        X_train, X_test, y_train, y_test = train_test_split(X,Y, test_size=0.3,random_state=42, shuffle=True)
        knn = KNeighborsClassifier(n_neighbors=1)
        #Train the model using the training sets
        knn.fit(X_train, y_train)
        #Predict the response for test dataset
        y_pred = knn.predict(X_test)
        cm = confusion_matrix(y_test, y_pred)
        matrix = plot_confusion_matrix(knn, X_test, y_test, cmap=plt.cm.Blues)
        matrix.ax_.set_title('Confusion Matrix')
        plt.show()
        print(classification_report(y_test, y_pred))
        print("Accuracy score :",metrics.accuracy_score(y_test, y_pred))

    elif choice==2:
        featuresList=["X_Minimum", "X_Maximum", "Y_Minimum","X_Perimeter"]
        X = df1[featuresList].to_numpy() # choosing features from features list
        Y = df1["Class"].to_numpy() # choosing type of steel  as the labels
        #splitting  features and labels as train and test set 70, 30% respectively
        X_train, X_test, y_train, y_test = train_test_split(X,Y, test_size=0.3,random_state=42, shuffle=True)
        knn = KNeighborsClassifier(n_neighbors=3)
        #Train the model using the training sets
        knn.fit(X_train, y_train)
        #Predict the response for test dataset
        y_pred = knn.predict(X_test)
        cm = confusion_matrix(y_test, y_pred)
        matrix = plot_confusion_matrix(knn, X_test, y_test, cmap=plt.cm.Blues)
        matrix.ax_.set_title('Confusion Matrix')
        plt.show()
        print(classification_report(y_test, y_pred))
        print("Accuracy score :",metrics.accuracy_score(y_test, y_pred))
       

    elif choice==3: 
        featuresList=["X_Minimum", "X_Maximum", "Y_Minimum","X_Perimeter"]
        X = df1[featuresList].to_numpy() # choosing features from features list
        Y = df1["Class"].to_numpy() # choosing type of steel  as the labels
        #splitting  features and labels as train and test set 70, 30% respectively
        X_train, X_test, y_train, y_test = train_test_split(X,Y, test_size=0.3,random_state=42, shuffle=True)
        knn = KNeighborsClassifier(n_neighbors=5)
        #Train the model using the training sets
        knn.fit(X_train, y_train)
        #Predict the response for test dataset
        y_pred = knn.predict(X_test)
        cm = confusion_matrix(y_test, y_pred)
        matrix = plot_confusion_matrix(knn, X_test, y_test, cmap=plt.cm.Blues)
        matrix.ax_.set_title('Confusion Matrix')
        plt.show()
        print(classification_report(y_test, y_pred))
        print("Accuracy score :",metrics.accuracy_score(y_test, y_pred))
       
     
    elif choice==4:
        scaler = preprocessing.MinMaxScaler()
        names = df1.columns
        d = scaler.fit_transform(df1)
        scaled_df = pd.DataFrame(d, columns=names)
        scaled_df.head()
        # print(scaled_df)
        featuresList=["X_Minimum", "X_Maximum", "Y_Minimum","X_Perimeter"]
        X = scaled_df[featuresList].to_numpy() # choosing features from features list
        Y = scaled_df["Class"].to_numpy() # choosing type of steel  as the labels
        #splitting  features and labels as train and test set 70, 30% respectively
        X_train, X_test, y_train, y_test = train_test_split(X,Y, test_size=0.3,random_state=42, shuffle=True)
        knn = KNeighborsClassifier(n_neighbors=1)
        #Train the model using the training sets
        knn.fit(X_train, y_train)
        #Predict the response for test dataset
        y_pred = knn.predict(X_test)
        cm = confusion_matrix(y_test, y_pred)
        matrix = plot_confusion_matrix(knn, X_test, y_test, cmap=plt.cm.Blues)
        matrix.ax_.set_title('Confusion Matrix')
        plt.show()
        print(classification_report(y_test, y_pred))
        print("Accuracy score :",metrics.accuracy_score(y_test, y_pred))
        

    elif choice==5:
        scaler = preprocessing.MinMaxScaler()
        names = df1.columns
        d = scaler.fit_transform(df1)
        scaled_df = pd.DataFrame(d, columns=names)
        scaled_df.head()
        # print(scaled_df)
        featuresList=["X_Minimum", "X_Maximum", "Y_Minimum","X_Perimeter"]
        X = scaled_df[featuresList].to_numpy() # choosing features from features list
        Y = scaled_df["Class"].to_numpy() # choosing type of steel  as the labels
        #splitting  features and labels as train and test set 70, 30% respectively
        X_train, X_test, y_train, y_test = train_test_split(X,Y, test_size=0.3,random_state=42, shuffle=True)
        knn = KNeighborsClassifier(n_neighbors=3)
        #Train the model using the training sets
        knn.fit(X_train, y_train)
        #Predict the response for test dataset
        y_pred = knn.predict(X_test)
        cm = confusion_matrix(y_test, y_pred)
        matrix = plot_confusion_matrix(knn, X_test, y_test, cmap=plt.cm.Blues)
        matrix.ax_.set_title('Confusion Matrix')
        plt.show()
        print(classification_report(y_test, y_pred))
        print("Accuracy score :",metrics.accuracy_score(y_test, y_pred))
        
        
    elif choice==6:
        scaler = preprocessing.MinMaxScaler()
        names = df1.columns
        d = scaler.fit_transform(df1)
        scaled_df = pd.DataFrame(d, columns=names)
        scaled_df.head()
        # print(scaled_df)
        featuresList=["X_Minimum", "X_Maximum", "Y_Minimum","X_Perimeter"]
        X = scaled_df[featuresList].to_numpy() # choosing features from features list
        Y = scaled_df["Class"].to_numpy() # choosing type of steel  as the labels
        #splitting  features and labels as train and test set 70, 30% respectively
        X_train, X_test, y_train, y_test = train_test_split(X,Y, test_size=0.3,random_state=42, shuffle=True)
        knn = KNeighborsClassifier(n_neighbors=5)
        #Train the model using the training sets
        knn.fit(X_train, y_train)
        #Predict the response for test dataset
        y_pred = knn.predict(X_test)
        cm = confusion_matrix(y_test, y_pred)
        matrix = plot_confusion_matrix(knn, X_test, y_test, cmap=plt.cm.Blues)
        matrix.ax_.set_title('Confusion Matrix')
        plt.show()
        print(classification_report(y_test, y_pred))
        print("Accuracy score :",metrics.accuracy_score(y_test, y_pred))
             
    elif choice==7:
        break;   
    
    else:
        print("enter valid information")
        