#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int a,b,tt;
        scanf("%d",&n);
        a=n>>4;
        b=n<<4;
        b=b&255;
        tt=a|b;
        printf("%d",tt);
    }
    return 0;
}
