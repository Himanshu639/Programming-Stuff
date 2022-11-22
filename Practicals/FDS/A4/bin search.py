'''
Assignment No. 4
Problem Statement:- Store names and phone numbers of friends in sorted order of names and search your friend from the list using fibonacci search, also insert friend if not in phonebook
'''

def sort(n,a,x):
    for i in range(n):
        for j in range(i):
            if a[i]<a[j]:
                temp = a[i]
                a[i] = a[j]
                a[j] = temp
                temp = x[i]
                x[i] = x[j]
                x[j] = temp

def tab(n,a,b):

    print("\n\n\n\n\n\n")
    for i in range(30):
        print("= ",end='')
    print("\n")
    print("Sr. no.".ljust(12),end='')
    print("Names".ljust(12),end='')
    print("Ph. No.".ljust(12))

    print("\n")

    for i in range(n):
        print("%d".ljust(12) %i,end='')
        print("%s".ljust(12) %a[i],end='')
        print("%d" %b[i])

    for i in range(30):
        print("= ",end='')
    print("\n")

def search(n,a,b):
    l=0
    h=n-1
    name=input("What to search?\n").capitalize()
    print("\n\n")
    while(1):
        mid=int((l+h)/2)
        if a[mid]==name:
            print("%s found at %d" %(name,mid))
            print("\n")
            break
        elif l>=h:
            print("%s not found\n\n" %(name))
            print("Do you want to add it?\n(y/n)")
            ch=input()
            if ch=='y':
                n+=1
                a.append(name)
                b.append(int(input("\n\nEnter No. of the person\n")))
                sort(n,a,b)
                print("\n\nWant Tablur form?(y/n)\n")
                ch1=input()
                if ch1=='y':
                    tab(n,a,b)
                    
                elif ch1=='n':
                    break
                else:
                    print("Wrong Input\n")
            elif ch=='n':
                break
            else:
                print("Wrong Input\n")
            break
        elif name<a[mid]:
            h=mid-1
        elif name>a[mid]:
            l=mid+1
                
def accept():
    #Filling Contacts
    for i in range(n):
        cont_name.append(input("Enter the Name for person %d:- " %i).capitalize())
        cont_no.append(int(input("Enter the Number for person %d:- " %i)))



#starting of program
n=int(input("How many contacts?\n"))
cont_name=[]
cont_no=[]

accept()

sort(n,cont_name,cont_no) #sorting 

tab(n,cont_name,cont_no) #Creating table

search(n,cont_name,cont_no)