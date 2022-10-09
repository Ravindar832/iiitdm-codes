# cs20b1085 gugulothu ravindar

import csv
import pandas as pd

df1 = pd.read_csv("diabetes.csv")
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.cluster import KMeans, k_means
from sklearn.metrics import accuracy_score

while True:  
    print("MENU")  
    print("1.  minimum distance classifer utilizing built-in functions.")  
    print("2.  K- means algorithm utilizing built-in functions.")  
    print("3.  minimum distance classifer without using built-in functions")
    print("4.  K- means algorithm without using built-in functions") 
    print("5. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        featuresList=["Glucose", "Insulin", "Age"]
        features = df1[featuresList].to_numpy() # choosing features from features list
        label = df1["Outcome"].to_numpy() # choosing outcome(diabetes) as the labels
        #splitting  features and labels as train and test set 80, 20% respectively
        features_train, features_test, labels_train, labels_test = train_test_split(features, label, test_size=0.2)  
        classifier = KNeighborsClassifier(n_neighbors=1, weights="distance")  #initializing the minimum distance classifier 
        classifier.fit(features_train, labels_train) #Fit the k-nearest neighbors classifier from the training dataset.
        labels_prediction = classifier.predict(features_test) #predicting with the test data
        print("predicted test data ",labels_prediction) # printing the predicted test data
        accurate_mdc = accuracy_score(labels_prediction, labels_test)
        print(" minimum distance classifier by inbuilt = ", accurate_mdc)

    elif choice==2:
        featuresList=["Glucose", "Insulin", "Age"]
        features = df1[featuresList].to_numpy() # choosing features from features list
        label = df1["Outcome"].to_numpy() # choosing outcome(diabetes) as the labels
        #splitting  features and labels as train and test set 80, 20% respectively
        features_train, features_test, labels_train, labels_test = train_test_split(features, label, test_size=0.2)  
        kmeans_classifier = KMeans(n_clusters=2, random_state=0) #initializing the kmeans classifier 
        kmeans_classifier.fit(features_train) #Fit the k-means classifier from the training dataset.
        labels_prediction = kmeans_classifier.predict(features_test) #predicting with the test data
        print("predicted test data ",labels_prediction) # printing the predicted test data
        accurate_kmeans= accuracy_score(labels_prediction, labels_test)
        print(" k_means cluster   by inbuilt = ", accurate_kmeans)

    elif choice==3:
        featuresList=["Glucose", "Insulin", "Age"]
        features = df1[featuresList].to_numpy() # choosing features from features list
        label = df1["Outcome"].to_numpy() # choosing outcome(diabetes) as the labels
        #splitting  features and labels as train and test set 80, 20% respectively
        features_train, features_test, labels_train, labels_test = train_test_split(features, label, test_size=0.2)
        classifier = KNeighborsClassifier(n_neighbors=1, weights="distance")  #initializing the minimum distance classifier 
        classifier.fit(features_train, labels_train) #Fit the k-nearest neighbors classifier from the training dataset.
        labels_prediction = classifier.predict(features_test) #predicting with the test data
        print("predicted test data ",labels_prediction) # printing the predicted test data
        accurate_mdc = accuracy_score(labels_prediction, labels_test)
        print(" minimum distance classifier by inbuilt = ", accurate_mdc)

    
        
                      
        
        
    elif choice==4:
        featuresList=["Glucose", "Insulin", "Age"]
        features = df1[featuresList].to_numpy() # choosing features from features list
        label = df1["Outcome"].to_numpy() # choosing outcome(diabetes) as the labels
        #splitting  features and labels as train and test set 80, 20% respectively
        features_train, features_test, labels_train, labels_test = train_test_split(features, label, test_size=0.2)  
        kmeans_classifier = KMeans(n_clusters=2, random_state=0) #initializing the kmeans classifier 
        kmeans_classifier.fit(features_train) #Fit the k-means classifier from the training dataset.
        labels_prediction = kmeans_classifier.predict(features_test) #predicting with the test data
        print("predicted test data ",labels_prediction) # printing the predicted test data
        accurate_kmeans= accuracy_score(labels_prediction, labels_test)
        print(" k_means cluster   by inbuilt = ", accurate_kmeans)
         
    elif choice==5:
        break;   
    
    else:
        print("enter valid information")
        