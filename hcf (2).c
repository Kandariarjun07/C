#include<stdio.h>
int main()
{
    int a,b,n=1,hcf=0,l;
    printf("Enter the first number:");
    scanf("%d",&a);
    printf("Enter the second number:");
    scanf("%d",&b);
    l=a<b?a:b;
    while(n<=l) {
        if(a%n==0 && b%n==0) {
            hcf=n;
        }
        n++;
    }
    printf("The HCF is %d",hcf);
}