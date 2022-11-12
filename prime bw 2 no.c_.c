#include<stdio.h>
#include<math.h>
int main()
{
   int m,n,a,b;
   scanf("%d %d",&m,&n);
   if(m>n)
   {
     a=m;
     b=n;
    }
    else
    {
      a=n;
      b=m;
    }
   int l=(int)sqrt(a);
   for(int i=b;i<=a;i++)
   {
      int flag=0;
      for(int j=2;j<=l;j++)
       {
           if(i%j==0)
            {
              flag=1;
               break;
            }
         }
            if(flag==0) printf("%d is a prime\n",i);
            else printf("%d is a not a prime\n",i);
        }
     }
            
        