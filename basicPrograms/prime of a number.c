#include<stdio.h>
#include<math.h>
int main()
{
    int m,l,flag=0;
    scanf("%d",&m);
    l=(int)sqrt(m);
    for (int i=2; i<=l; i++) {
        if (m%i==0) {
            flag=1;
        }
    }
    if (flag==0) {
        printf("Prime");
    }
    else {
        printf("Not a prime");
    }
}