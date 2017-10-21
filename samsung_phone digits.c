#include<stdio.h>
const char HashT[10][5]={",","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
long long GetLength(char *s)
{
    long long int cnt=0;
    while(s[cnt]!='\0')
        cnt++;
    return cnt;
}
void GetString(long long int *arr,long long n,long long int cnt,char *ans)
{
    if(cnt==n)
    {
        printf("%s\n",ans);
        return ;
    }
    else
    {
        long long int i;
        long long int u=GetLength(HashT[arr[cnt]-1]);
        for(i=0;i<u;i++)
        {
            ans[cnt]=HashT[arr[cnt]-1][i];
            GetString(arr,n,cnt+1,ans);
        }
    }
}
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
         long long int i,n;
        scanf("%lld",&n);
         long long int arr[n+1];
         int f=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i]==1||arr[i]==0)
                f=1;
        }
         char ans[n+1];
        ans[n]='\0';
        if(!f)
        GetString(arr,n,0,ans);
    }
    return 0;
}
