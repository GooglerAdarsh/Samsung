#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long int n,m;
        cin>>n>>m;
        long int arr[n+1][m+1],cnt=0;
        map<long int ,bool >mp;
        for(long int i=0;i<n;i++)
            for(long int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j]&&!mp[j])
                {
                    mp[j]=true;
                    cnt++;
                }
            }
                cout<<cnt<<endl;
    }
    return 0;
}
