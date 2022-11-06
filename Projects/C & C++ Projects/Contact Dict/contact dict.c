#include <stdio.h>

struct contact {
    char name[30];
    int no;

};

int main() {
    int n;
    printf("How many contacts do you want to save?");
    scanf("%d", &n);

    
    for (int i=0; i<n; i++) {
        struct contact abc;
        scanf("%d", &abc.no);
        printf("The number is %d", abc.no);
    }
    return 0;
}