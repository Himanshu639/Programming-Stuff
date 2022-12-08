n=int(input("Enter the number of marks:- "))
print("\n")
ab=0
smark=[]

for i in range(n):
    while(1):
        ipmark=input("Enter marks of Student %d:- " %(i+1))
        if ipmark=='AB':
            ab+=1
            ipmark=-1
            break
        ipmark = int(ipmark)
        if (ipmark<=0 or ipmark>=100):
            print("Please Enter valid marks out of 100")
        else:
            break
    smark.append(int(ipmark))

def ave():
    sum=0
    for i in range(n):
        if (smark[i]!=-1):
            sum+=smark[i]
    print("The average of the all marks is ",(sum/(n-ab)))

def max():
    max=smark[0]
    for i in range(n):
        if max<smark[i]:
            max=smark[i]
    print("The maximum mark from all the marks is ",max)

def min():
    min=smark[0]
    for i in range(n):
        if (min>smark[i] and smark[i]!=-1):
            min=smark[i]
    print("The maximum mark from all the marks is ",min)

def abs():
    print("%d student/s is/are absent" %ab)

def hfreq():
    hfreq = 0
    index = 0
    for i in range(n):
        count = 0
        if (smark[i]==-1):
            continue
        for j in range(n):
            if (smark[i]==smark[j]):
                count+=1
        if count > hfreq:
            hfreq = count
            index = i
    if hfreq == 1:
        print("None of the mark has frequency greater than 1\n")
    else:
        print("Highest Frequency Mark:- %d\nFreq:- %d" %(smark[index],hfreq))

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