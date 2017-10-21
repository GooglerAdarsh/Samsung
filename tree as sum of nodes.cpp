#include<bits/stdc++.h>
using namespace std;
struct node {
struct node *left;
struct node *right;
long  int data;
};
struct node *newNode(long int da)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=da;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
long int GetSumRoot(struct node *root)
{
    if(root==NULL)
        return 0;
    long int old_val=root->data;
    root->data=GetSumRoot(root->left)+GetSumRoot(root->right);
    return root->data+old_val;
}
void print(struct node *root)
{
    if(root==NULL)
        return ;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
    long int t;
    struct node *root=NULL;
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
  GetSumRoot(root);
  print(root);
    return 0;
}
