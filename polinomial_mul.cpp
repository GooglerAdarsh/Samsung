#include<bits/stdc++.h>
using namespace std;
struct node {
int data;
int pow;
struct node *next;
};
map<int,struct node *>mp;
struct node *getnode(struct node *root,int a,int p)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->pow=p;
    temp->next=root;
    root=temp;
    return root;
}
void printdata(struct node *root)
{
    if(root==NULL)
        return ;
        cout<<root->data<<" "<<root->pow<<endl;
    printdata(root->next);
}
struct node *multi(struct node *root1,struct node *root2)
{
    struct node *root3=NULL;
    while(root1)
    {
        struct node *temp=root2;
        while(temp)
        {
            if(mp[root1->pow+temp->pow])
            {
                struct node *temp1=mp[root1->pow+temp->pow];
                temp1->data=temp1->data+(root1->data*temp->data);
            }
            else{
                struct node *temp1=(struct node *)malloc(sizeof(struct node));
                temp1->data=(root1->data*temp->data);
                temp1->pow=(root1->pow+temp->pow);
                temp1->next=root3;
                root3=temp1;
                mp[temp1->pow]=temp1;
            }
            temp=temp->next;
        }
       root1=root1->next;
    }
    return root3;
}
int main()
{
    struct node *root1=NULL,*root2=NULL,*root3=NULL;

    cout<<"Enter first polynomial//terminate on -10000"<<endl;

    while(1)
    {
        int a,p;
        cout<<"enter the value and power"<<endl;
        cin>>a>>p;
        if(a==-10000)
            break;
        root1=getnode(root1,a,p);
    }
  //  printdata(root1);

    cout<<"Enter 2end polynomial//terminate on -10000"<<endl;

    while(1)
    {
        int a,p;
        cout<<"enter the value and power"<<endl;
        cin>>a>>p;
        if(a==-10000)
            break;
        else
        {
            root2=getnode(root2,a,p);
        }
    }
    root3=multi(root1,root2);
    printdata(root3);
    return 0;
}
