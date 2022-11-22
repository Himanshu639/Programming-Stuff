''' 
Assignment No. 2
Problem Statement:- Finding longest string, higest occurance character from a string, Finding whether the string is palindrome, index of substring in main string and occurance of each word in a given string
'''


def hfreq():
    count=0
    s=input("Enter a String:- ")
    s=s.lower()
    ch=input("Enter a character:- ")
    ch=ch.lower()
    for i in range(len(s)):
	    if s[i]==ch:
	        count+=1
    ch=ch.upper()
    print("'%c' occurs in the string %d times\n\n\n" %(ch,count))
    
    
def palin():
    count=0
    s=input("Enter a string:- ")
    s=s.lower()
    for i in range(len(s)):
        if s[i]==s[i*(-1)-1]:
            count+=1
    if count==len(s):
        print("The given string is a palindrome\n\n\n")
    else:
        print("The given string is not a palindrome\n\n\n")
            
    
def _long():
    m_word=""
    word=""
    s=input("Enter a string:- ")
    for i in range(len(s)):
        if s[i]!=' ' and s[i]!=',' and s!=['.']:
            word+=s[i]
        if s[i]==' ' or (len(s)-1)==i:
            if len(m_word)<len(word):
                m_word=word
            word=""        
        
    print('The longest word from the given string is "%s"\n\n\n' %m_word)
    
    
def occ():
	
	s=input("Enter a string:- ")
	check=[]
	check1=[]
	word=""
	for i in range(len(s)):
		if s[i]!=' ':
			word+=s[i]
		if s[i]==' ' or len(s)-1==i:
			check1.append(word)
			count=1
			for j in range(len(check)):
				if check[j]==word:
					count+=1
			if count==1:
				check.append(word)
			word=""

	for i in range(len(check)):
		count=0
		for j in range(len(check1)):
			if check[i]==check1[j]:
				count+=1
		print("%s: %d" %(check[i],count))
		print("\n\n\n")
    	
def sub():
	s= input("enter main string:- ")
	s1=input("enter the sub string to check:- ")
	word=""
	check=1
	for i in range (len(s)-len(s1)+1):
		for j in range(i,i+len(s1)):
			word+=s[j]
		if s1==word:
			print('"%s" occurs in the string at %d\n\n\n' %(s1,i+1))
			check+=1
		word=""
	if check==1:
		print('"%s" does not occur in the string\n\n\n' %s1)
        

while True:
	print("Which operation do you want to perform?\n1. Find longest string\n2. Find higest occurance character from a string\n3. Find whether the string is palindrome\n4. index\n5. find substring\n 6. exit\n")
	ip= int(input("Enter the input:- "))
	if ip==1:
		_long()
	if ip==2:
		hfreq()
	if ip==3:
		palin()
	if ip==4:
		occ()
	if ip==5:
		sub()
	if ip==6:
		break
