def insertion_sort(list1):
    for i in range(1, len(list1)):
        temp = list1[i]
        j = i-1
        while temp < list1[j] and j > -1:
            list1[j+1] = list1[j] 
            list1[j] = temp
            j -= 1
    return list1

list1 = [] 

n = int(input("Enter number of elements : "))

for x in range(0, n):
    ele = int(input())
 
    list1.append(ele) # adding the element
     
insertion_sort(list1)
print(list1)

