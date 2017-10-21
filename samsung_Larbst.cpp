#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
struct Node
{
    struct Node *left;
    struct Node *right;
    long long int data;
};
struct INFO
{
    long long int size1;
    long long int max1;
    long long int min1;
    long long int ans;
    bool bst;
};
INFO larBST(struct Node *root)
{
    if(root==NULL)
    return {0,INT_MIN,INT_MAX,0,true};
    if(root->left==NULL && root->right==NULL)
    return {1,root->data,root->data,1,true};
    INFO l=larBST(root->left);
    INFO r=larBST(root->right);
    INFO tem;
    tem.size1=(1+l.size1+r.size1);
    if(l.bst && r.bst && l.max1 < root->data && r.min1 > root->data)
    {
        tem.min1=min(l.min1,min(r.min1,root->data));
        tem.max1=max(r.max1,max(l.max1,root->data));
        tem.ans=tem.size1;
        tem.bst=true;
        return tem;
    }
    tem.ans=max(l.ans,r.ans);
     tem.bst=false;
    return tem;
}
struct Node *newNode(long long int da)
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=da;
    return temp;
};
int main()
{
    struct Node *root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    root->right->left = newNode(45);
    printf("%lld\n",larBST(root).ans);
    return 0;
}
