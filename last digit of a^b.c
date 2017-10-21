#include<stdio.h>
long long GetLength(char *a)
{
    long long cnt=0;
    while(a[cnt]!='\0')
        cnt++;
    return cnt;
}
long long Modulus(char *b,long long int BLen)
{
    long long int i=0,mod=0;
    for(i=0;i<BLen;i++)
        mod=(mod*10+(long long int)b[i]-(long long int)'0')%4;
    return mod;
}
long long int GetLastDigit(char *a,char *b)
{
    long long la=GetLength(a),exp=0;
    long long lb=GetLength(b);
    if(la==1&&lb==1&&a[0]=='0'&&b[0]=='0')
        return 1;
    if(la==1&&a[0]=='0')
        return 0;
    if(lb==1&&b[0]=='0')
        return 1;
       long long t=Modulus(b,lb);
    if(t==0)
        exp=4;
    else
        exp=t;
    long long tt1=((long long int)a[la-1]-(long long int)'0'),i;
    long long tt=tt1;
        for(i=1;i<exp;i++)
            tt=tt*tt1;
        return (tt%10);
}
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int ans;
        char a[1000],b[1000];
        scanf("%s%s",&a,&b);
        ans=GetLastDigit(a,b);
        printf("%lld\n",ans);
    }
    return 0;
}
