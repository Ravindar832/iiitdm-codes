def binary_search(list1, n):  
    low = 0  
    high = len(list1) - 1  
    mid = 0  
  
    while low <= high:  
        mid = (high + low) // 2    
        if list1[mid] < n:  
            low = mid + 1  
        elif list1[mid] > n:  
            high = mid - 1   
        else:  
            return mid    
    return -1  
  
  # elemebts in list
list1 = [] 

i = int(input("Enter number of elements : "))

for j in range(0, i):
    ele = int(input())
 
    list1.append(ele) # adding the element
     
list1.sort()
print(list1)
n = int(input('enter the number '))
  
# Function call   
result = binary_search(list1, n)  
  
if result != -1:  
    print("Element is present at index", int(result))  
else:  
    print("Element is not present in list1") 