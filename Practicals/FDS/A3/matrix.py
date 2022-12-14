''' 
Assignment No. 3
Problem Statement:- Operation on matrix(addition, subtraction, multiplication, transpose)
'''


def add():

    r1 = int(input("Enter the number of rows for 1st array:- "))
    c1 = int(input("Enter the number of columns for 1st array:- "))

    arr1 = []
    print("enter the elements\n")
    for i in range(r1*c1):
        arr1.append(int(input()))

    print("The first array is\n\n")
    for i in range(c1*r1):
        print("%d".ljust(4) % arr1[i], end=' ')
        if (i+1) % c1 == 0:
            print("\n")
    print("\n")

    r2 = int(input("Enter the number of rows for 2nd array:- "))
    c2 = int(input("Enter the number of columns for 2nd array:- "))

    arr2 = []
    print("enter the elements\n")
    for i in range(r2*c2):
        arr2.append(int(input()))

    print("The second matrix is\n")
    for i in range(c2*r2):
        print("%d".ljust(4) % arr2[i], end=' ')
        if (i+1) % c2 == 0:
            print("\n")
    print("\n")

    if r1 != r2 or c1 != c2:
        print("Incompatible matrix for addition\n\n\n\n")
    else:
        sum = []
        for i in range(r1*c2):
            sum.append(arr1[i]+arr2[i])

        print("The sum of martix is\n")
        for k in range(r1*c2):
            print("%d".ljust(4) % sum[k], end=' ')
            if (k+1) % c2 == 0:
                print("\n")
        print("\n")


def sub():

    r1 = int(input("Enter the number of rows for 1st array:- "))
    c1 = int(input("Enter the number of columns for 1st array:- "))

    arr1 = []
    print("enter the elements\n")
    for i in range(r1*c1):
        arr1.append(int(input()))

    print("The first array is\n\n")
    for i in range(c1*r1):
        print("%d".ljust(4) % arr1[i], end=' ')
        if (i+1) % c1 == 0:
            print("\n")
    print("\n")

    r2 = int(input("Enter the number of rows for 2nd array:- "))
    c2 = int(input("Enter the number of columns for 2nd array:- "))

    arr2 = []
    print("enter the elements\n")
    for i in range(r2*c2):
        arr2.append(int(input()))

    print("The second array is\n\n")
    for i in range(c2*r2):
        print("%d".ljust(4) % arr2[i], end=' ')
        if (i+1) % c2 == 0:
            print("\n")
    print("\n")

    if r1 != r2 or c1 != c2:
        print("Incompatible matrix for subtraction\n\n\n\n")
    else:
        sub = []
        for i in range(r1*c2):
            sub.append(arr1[i]-arr2[i])

        print("The subtraction of martix is\n")
        for k in range(r1*c2):
            print("%d".ljust(4) % sub[k], end=' ')
            if (k+1) % c2 == 0:
                print("\n")
        print("\n")


def trans():
    r1 = int(input("Enter the number of rows:- "))
    c1 = int(input("Enter the number of columns:- "))
    arr1 = []
    print("enter the elements\n")
    for i in range(r1*c1):
        arr1.append(int(input()))

    print("The matrix is\n")
    for i in range(c1*r1):
        print("%d".ljust(4) % arr1[i], end=' ')
        if (i+1) % c1 == 0:
            print("\n")

    tra = []
    r2 = c1
    c2 = r1
    for i in range(c1):
        for j in range(r1):
            tra.append(arr1[(c1*j)+i])

    print("\n\nTranspose of the matrix is\n")
    for i in range(c2*r2):
        print("%d".ljust(4) % tra[i], end=' ')
        if (i+1) % c2 == 0:
            print("\n")


def mul():
    r1 = int(input("Enter the number of rows for 1st array:- "))
    c1 = int(input("Enter the number of columns for 1st array:- "))

    arr1 = []
    print("enter the elements\n")
    for i in range(r1*c1):
        arr1.append(int(input()))

    print("The first array is\n\n")
    for i in range(c1*r1):
        print("%d".ljust(4) % arr1[i], end=' ')
        if (i+1) % c1 == 0:
            print("\n")
    print("\n")

    r2 = int(input("Enter the number of rows for 2nd array:- "))
    c2 = int(input("Enter the number of columns for 2nd array:- "))

    arr2 = []
    print("enter the elements\n")
    for i in range(r2*c2):
        arr2.append(int(input()))

    print("The second matrix is\n")
    for i in range(c2*r2):
        print("%d".ljust(4) % arr2[i], end=' ')
        if (i+1) % c2 == 0:
            print("\n")
    print("\n")

    if c1 != r2:
        print("Incompatiable for multiplication\n\n\n\n")
    else:
        var = 0
        mul = []
        for a in range(r1):
            for c in range(c2):
                for b in range(c1):
                    var += arr1[b+a*c1]*arr2[b*c2+c]
                mul.append(var)
                var = 0

        print("The multiplied matrix is\n")
        for i in range(r1*c2):
            print("%d".ljust(4) % mul[i], end=' ')
            if (i+1) % c2 == 0:
                print("\n")


while True:

    print("select operation from below operation list\n1. Addition of two matrices\n2. Subtraction of two matrices\n3. Multiplication of two matrices\n4. Transpose of entered matrix\n5. exit")
    ch = int(input(""))
    if ch == 1:
        add()
    elif ch == 2:
        sub()
    elif ch == 3:
        mul()
    elif ch == 4:
        trans()
    elif ch == 5:
        break
    else:
        print("\nInvalid choice\n")
