#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *newNode(int data1)
{
    struct node*temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data1;
    temp->left=NULL;
    temp->right=NULL;
    return (temp);
};
int toSumTree1(struct node *root)
{
    if(root==NULL)
        return 0;
    else{
        int old=root->data;
         root->data=toSumTree1(root->left)+toSumTree1(root->right);
         return root->data+old;
    }
}
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

}
int main()
{
    struct node *root = NULL;
  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
  toSumTree1(root);
  inorder(root);
    return 0;
}
