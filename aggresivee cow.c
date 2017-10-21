#include<stdio.h>
long long int fun(long long int *arr,long long int n,long long int c,long long int  mid)
{
    long long int  cnt=1,pre=arr[0],i;
     for(i=1;i<n;i++)
     {
         if(arr[i]-pre>=mid)
         {
             cnt++;
             if(cnt==c)
                return 1;
            pre=arr[i];
         }
     }
     return 0;
}
long long int BST(long long int *arr,long long int n,long long int c)
{
    long long int l=0,r=arr[n-1];
    while(l<r)
    {
        long long int mid=(l+r)/2;
        if(fun(arr,n,c,mid)==1)
            l=mid+1;
        else
            r=mid;
    }
    return l-1;
}
void heapfy(long long int *arr,long long int i,long long int n)
{
    long long int l,r;

    l=2*i+1;
    r=2*i+2;
     long long int lar=i;
    if(arr[l]>arr[lar]&&l<n)
        lar=l;
    if(arr[r]>arr[lar]&&r<n)
        lar=r;
    if(lar!=i)
    {
        long long int tem;
        tem=arr[lar];
        arr[lar]=arr[i];
        arr[i]=tem;
        heapfy(arr,lar,n);
    }
}

void heapsort(long long int *arr,long long int n)
{
    long long int i;
    for(i=n/2-1;i>=0;i--)
    {
        heapfy(arr,i,n);
    }
    for(i=n-1;i>=0;i--)
    {
        long long int temp;
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapfy(arr,0,i);
    }
}

int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,i,c,ans=0;
        scanf("%lld",&n);
         scanf("%lld",&c);
        long long int arr[n+3];
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

            heapsort(arr,n);
        ans=BST(arr,n,c);
        printf("%lld\n",ans);
    }
    return 0;
}
