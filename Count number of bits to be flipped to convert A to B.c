#include<stdio.h>
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int A,B,cnt=0;
        int a,b;
        scanf("%ld%ld",&A,&B);
        while(A&&B)
        {
            a=A&1;
            b=B&1;
            A=A>>1;
            B=B>>1;
            if(a^b)
                cnt++;
        }
        while(A)
        {
         a=A&1;
         A=A>>1;
         if(a)
         cnt++;
        }
        while(B)
        {
         b=B&1;
         B=B>>1;
         if(b)
         cnt++;
        }
        printf("%ld\n",cnt);
    }
    return 0;
}
