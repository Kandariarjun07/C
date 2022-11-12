#include<stdio.h>
int main()
{
    char a;
    printf("Enter the character:\n");
    scanf("%c",&a);
    if (a>=65 && a<=90 || a>=97 && a<=122) {
        printf("Entered character is an alphabet!!");
    }
    else if(a>=48 && a<=57) {
        printf("Entered character is a number!!!");
    }
    else {
        printf("Entered character is a symbol!!!");
    }
}