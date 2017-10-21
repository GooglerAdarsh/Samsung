#include<bits/stdc++.h>
using namespace std;
 long int arr[100][100],n,m;
 int dfs(int i,int j,int sum)
 {
     i=i-1;
     if(i<0||j<0||i>=n||j>=m||arr[i][j]==2)
        return 0;
     else
     {
         cout<<sum<<endl;
         if(arr[i][j]==1||((j-1)>=0&&arr[i][j-1])||(j+1<n&&arr[i][j]))
         sum++;
        return max(sum,max(dfs(i,j-1,sum),dfs(i,j+1,sum)));
     }
 }
int main()
{
    cin>>n>>m;
    for(long int i=0;i<n;i++)
    {
        for(long int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    bool f=false;
        long int cnt=5;
    for(long int i=n-1;i>=0;i--)
    {
        for(long int j=0;j<m;j++)
        {
            if(arr[i][j]==2)
                f=true;
                if(f&&cnt>0&&arr[i][j]==2)
                    arr[i][j]=0;
        }
            if(f)
                cnt--;
    }
    cout<<dfs(n,m/2,0)<<endl;
  /*  cout<<endl;
    for(long int i=0;i<n;i++)
    {
        for(long int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
