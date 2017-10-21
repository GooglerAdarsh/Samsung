#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        string s,s1="";
        cin>>s;
        long int i=0;
        long int cnta=0,cnte=0,cnti=0,cnto=0,cntu=0;
        while(s[i]!='\0')
        {
            string s1="";
            while(s[i]!='\0'&&(s[i]=='a'||s[i]=='e'||s[i]=='u'||s[i]=='i'||s[i]=='o'))
            {
                s1+=s[i];
                if(s[i]=='a')
                    cnta++;
                else if(s[i]=='e')
                    cnte++;
                else if(s[i]=='i')
                    cnti++;
                else if(s[i]=='o')
                    cnto++;
                else if(s[i]=='u')
                    cntu++;
                    if(cnta!=0&&cnte!=0&&cnti!=0&&cnto!=0&&cntu!=0)
                        cout<<s1<<" ";
                i++;
            }
            i++;
        }
    }
    return 0;
}
