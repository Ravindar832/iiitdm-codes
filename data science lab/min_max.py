
# def linearSearch(array, n, x):

#     # Going through array sequencially
#     for i in range(0, n):
#         if (array[i] == x):
#             return i
#     return -1


array = []
a = int(input("Enter number of elements : "))

for i in range(0, a):
    ele = int(input())
 
    array.append(ele) # adding the element

x = max(array)
y = min(array)
# n = len(array)
# result = linearSearch(array, n, x)
# result = linearSearch(array, n, y)
print("max=", x)
print("min=", y)

