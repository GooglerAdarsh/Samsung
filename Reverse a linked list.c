#include<stdio.h>
struct node {
int data;
struct node *next;
};
struct node *reverselist(struct node *root)
{
    struct node *prev=NULL,*next1=NULL,*curr=root;
    if(root==NULL)
        return NULL;
   while(curr)
   {
       next1=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next1;
   }
   root=prev;
 return root;
}
struct node *getnewnode(int a)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    return temp;
}
int main()
{
    struct node *root=NULL,*temp,*temp1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        scanf("%d",&a);
        if(root==NULL)
        {
            root=getnewnode(a);
            temp=root;
           // temp=temp->next;
        }
        else
        {
            temp->next=getnewnode(a);
            temp=temp->next;
        }
    }
    root=reverselist(root);
   temp1=root;
    while(temp1)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    return 0;
}
