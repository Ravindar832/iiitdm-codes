import numpy as np

R = int(input("Enter the number of rows:"))
C = int(input("Enter the number of columns:"))

print("Enter the entries in a single line (separated by space): ")

entries = list(map(int, input().split()))

matrix1 = np.array(entries).reshape(R, C)
print("m1 = ", matrix1 )

R = int(input("Enter the number of rows:"))
C = int(input("Enter the number of columns:"))

print("Enter the entries in a single line (separated by space): ")

entries = list(map(int, input().split()))

matrix2 = np.array(entries).reshape(R, C)
print("m2 = " ,matrix2)

while True:  
    print("MENU")  
    print("1. matrix addition ")  
    print("2. matrix subtraction")  
    print("3. scalar matrix multiplication")
    print("4. Elementwise Matrix Multiplication")
    print("5. Matrix Multiplication")
    print("6. Matrix Transpose")
    print("7. Trace of a Matrix")
    print("8. Solve System of Linear Equations")
    print("9. Determinant")
    print("10. Inverse")
    print("11. Singular Value Decomposition")
    print("12. Eigen Value")
    print("13. Search an Element")
    print("14. Difference of Sum of Upper and Lower Triangular Matrix")    
    print("15. Exit")  
    choice = int(input("\nEnter your Choice: "))

    if choice == 1:
        print("m1 = ", matrix1)
        print("m2 = " ,matrix2)
        print(matrix1+matrix2)
    elif choice==2:
        print("m1 = ", matrix1)
        print("m2 = " ,matrix2)
        print(matrix1-matrix2)
    elif choice==3:
        scalar = int(input("enter the scalar Element"))
        new_matrix = matrix1 * scalar
        print("Scalar Product Matrix is : ")
        print(new_matrix)
        
        new_matrix = matrix2 * scalar
        print("Scalar Product Matrix is : ")
        print(new_matrix)
  
    elif choice==4:
        print(np.multiply(matrix1,matrix2))
        
    elif choice==5:
        result = np.dot(matrix1,matrix2)
        print(result)
    
    elif choice==6:
        print (matrix1.T)
        print (matrix2.T)
        
    elif choice==7:
        result1 = matrix1.trace()
        print(result1)
        
        result2 = matrix2.trace()
        print(result2)
        
    elif choice==8:
        R = int(input("Enter the number of rows:"))
        C = int(input("Enter the number of columns:"))

        print("Enter the entries in a single line (separated by space): ")

        entries = list(map(int, input().split()))

        matrix3 = np.array(entries).reshape(R, C)
        print("m1 = ", matrix3 )

        R = int(input("Enter the number of rows:"))
        C = int(input("Enter the number of columns:"))

        print("Enter the entries in a single line (separated by space): ")

        entries = list(map(int, input().split()))

        matrix4 = np.array(entries).reshape(R, C)
        print("m2 = " ,matrix4)
        C = np.linalg.solve(matrix3, matrix4)
        print(C)
        
    elif choice==9:
        det1 = np.linalg.det(matrix1)
        print("det1 = ")
        print(int(det1))
        det2 = np.linalg.det(matrix2)
        print("det2 = ")
        print(int(det2))
        
    elif choice==10:
        print(np.linalg.inv(matrix1))
        print(np.linalg.inv(matrix2))
        
    elif choice==11:
        u, s, vh = np.linalg.svd(matrix1, full_matrices=False)
        print(u, s, vh, "\n")
        
        u, s, vh = np.linalg.svd(matrix2, full_matrices=False)
        print(u, s, vh, "\n")
        
    elif choice==12:
        w1 = np.linalg.eig(matrix1)
        print("matrix1=",w1)
        
        w2 = np.linalg.eig(matrix2)
        print("matrix2=",w2)
        
    elif choice==13:
        k = int(input("Enter the element to search: "))
        i = np.where(matrix1 == k)
        print("Position of k in matrix matrix1 is: \n")
        print(i, "\n")
            
        
    elif choice==14:
        R = int(input("Enter the number of rows:"))
        C = int(input("Enter the number of columns:"))
        matrix5 = np.array([[int(input(f'Enter the element at [{r},{c}]: ')) for c in range(C)]for r in range(R)])
        sumUpper = 0
        sumLower = 0
        for r in range(R):
            for c in range(C):
                if(r <= c):
                    sumUpper += matrix1[r][c]
                if(c <= r):
                    sumLower += matrix1[r][c]
        print("difference ", abs(sumUpper-sumLower))            
		
            
    elif choice==15:
        break;   
    
    else:
        print("enter valid information")

 
