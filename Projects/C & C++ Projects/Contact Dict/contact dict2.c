#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void delay(int number_of_seconds)

{

// Converting time into milli_seconds

int milli_seconds = 1000 * number_of_seconds;

// Storing start time

clock_t start_time = clock();

// looping till required time is not achieved

while (clock() < start_time + milli_seconds) ;

}

int main()
{       int ip;
        int n=0;
        unsigned long long int no[1000];
        char str[1000][20];
        char email[1000][50];
        
        while(1) {
        printf("***** MENU *****\n");
        printf("1. Create a new contact\n2. List all contacts\n3. Delete a contact\n4. Update a contact\n5. exit\n\n");
        printf("Enter your choice:- ");
        scanf("%d", &ip);
        printf("\n");
        printf("\n");

        if (ip==1) {
        printf("Enter the name of the contact:- ");
   
        scanf("%s",&str[n]); 


        printf("Enter the number of the contact:- ");

        scanf("%llu", &no[n]);
       

        printf("Enter the email of the contact:- ");

        scanf("%s", &email[n]);
        
        n++;

        printf("Your contact has been saved.\n\n");
        delay(2);
        system ("cls");

        } 
        
        else if (ip==2) {

        printf("%d contacts found.\n\n", n);
    
        for (int i=0; i<n; i++) {
            printf("Person %d\nName:- ", i+1);
            printf("%s", str[i]);
            printf("\n");
            printf("Phone Number:- ");
            printf("%llu", no[i]);
            printf("\n");
            printf("Email ID:- ");
            printf("%s",email[i]);
            printf("\n\n");
            
    }
    
        delay(5);
        system ("cls");
        }
        
    else if(ip==3) 
    {
        if (n==0) {
        printf ("There are no contacts to delete\n");
        delay(2);
        system("cls");
        
        } else {
        
        int del;
        for (int i=0; i<n; i++) {
            printf("Person %d\nName:- ", i+1);
            printf("%s\n", str[i]);
            printf("\n");
        }
        
        printf("Which contact do you want to delete?(Please enter person number)\n");
        scanf("%d", &del);
        if (del>n) {
        printf("There are only %d contacts\n",n);
        delay(2);
        system ("cls");
        } else {
        del--;
        for (int i=del; i<n;i++) {
        
            strcpy(str[i], str[i+1]);
            no[i]=no[i+1];
            strcpy(email[i], email[i+1]);
        }
        
        n--;
        printf("Contact deleted successfully!\n\n");
        delay(2);
        system ("cls");
        }
        }
        
    } else if(ip==4) {
    
        if (n==0) {
        printf("There are no contacts to update.\n");
        delay(2);
        system ("cls");
        
        } else {
        int upd,ch;
        
        for (int i=0; i<n; i++) {
            printf("Person %d\nName:- ", i+1);
            printf("%s\n", str[i]);
            printf("\n");
        }
        
        printf("\nWhich contact do you want to update?\n");
        
        scanf("%d", &upd);
        if (upd>n) {
        printf("There are only %d contacts\n", n);
        delay(2);
        system("cls");
        } else {
        upd--;
        
        printf("\nWhat do you want to update?\n1. Name of the contact\n2. Phone number of the contact\n3. Email ID of the contact\n\nEnter your choice:- ");
        scanf("%d", &ch);
        
        if (ch==1) {
            printf("Enter the new name of the person:- ");

            scanf("%s",&str[upd]);
            printf("Your contact name has been updated successfully\n");
            delay(2);
            system ("cls");
            
        } else if (ch==2) {
            printf("Enter the new phone number of the person:- ");
            
            scanf("%llu", &no[upd]);
            printf("Your contact phone number has been updated successfully\n");
            delay(2);
            system ("cls");
            
        } else if (ch==3) {
            printf("Enter the new email id of the person:- ");
            
            scanf("%s", &email[upd]);
            printf("Your contact Email ID has been updated successfully\n\n");
            delay(2);
            system ("cls");
            
        } else {
            printf("Invalid input\n");
            delay(2);
            system ("cls");
        }
        }
        }
        
    } else if (ip==5){
        break;
    } else {
        printf("Invalid input\n\n");
        delay(2);
        system ("cls");
    }
        

    }
        return 0;
}