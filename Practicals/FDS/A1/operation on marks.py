n=int(input("Enter the number of marks:- "))
print("\n")
ab=0
smark=[]

for i in range(n):
    ipmark=input("Enter marks of Student %d:- " %(i+1))
    if ipmark=='AB':
        ab+=1
        continue
    smark.append(int(ipmark))
n-=ab

def ave():
    sum=0
    for i in range(n):
        sum+=smark[i]
    print("The average of the all marks is ",(sum/n))

def max():
    max=smark[0]
    for i in range(n):
        if max<smark[i]:
            max=smark[i]
    print("The maximum mark from all the marks is ",max)

def min():
    min=smark[0]
    for i in range(n):
        if min>smark[i]:
            min=smark[i]
    print("The maximum mark from all the marks is ",min)

def abs():
    print("%d student/s is/are absent" %ab)

def hfreq():
    occ=[]
    for i in range(n):
        count=0
        for j in range(n):
            if smark[i]==smark[j]:
                count+=1
        occ.append(count)
    max=occ[0]
    index=0
    for i in range(n):
        if max<occ[i]:
            max=occ[i]
            index=i
    if max==1:
        print("None of the mark has frequency greater than 1\n")
    else:
        print("Mark with highest frequecy is %d with frequency %d" %(smark[index],max))

while(1):
    print("\n\n\n* * * * MENU * * * *\n1. Find Average of marks\n2. Find the highest mark\n3. Find the lowest mark\n4. Find No. of Absent stu.\n5. Find the Highest freq. mark\n")
    ch=int(input("Enter your choice:- "))

    if ch==1:
        ave()
    elif ch==2:
        max()
    elif ch==3:
        min()
    elif ch==4:
        abs()
    elif ch==5:
        hfreq()