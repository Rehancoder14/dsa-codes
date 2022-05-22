/* Beginning with an empty binary search tree,
  Construct binary search tree by inserting the values
  in the order given. After constructing a binary tree-
    i. Insert new node
    ii. Find number of nodes in longest path
    iii. Minimum data value found in the tree
    iv. Change a tree so that the roles of the left and
    right pointers are swapped at every node (Mirror Image).
    v. Search a value
*/
#include<iostream>
#include<stdio.h>
using namespace std;

//Node Structure
class node
{
   private:
     node *left, *right;
     int data;
   public:
     node(){
         left=right=NULL;
         data=0;
     }
   friend class bst;
};

class bst {
  private:
       node *root;
  public:
       bst(){
              root=NULL;
            }
       node* getRoot(){
              return root;
            }
       void insert(int);
       void display(node*);
       void preOrder(node *travel);
       void inOrder(node *travel);
       void postOrder(node *travel);
       int findMinnimum();
       void mirror(node*);
 	   int maxDepth(node*);
 	   void search(int key,node* root);
};
//Inserting a node into the BST
void bst::insert(int newData)
{
 node *newNode=new node();
 newNode->data=newData;
 node *travel=root;
 if(root==NULL)
  root=newNode;
 while(travel!=NULL)
 {
   if(newData>=travel->data)
   {
        if(travel->right!=NULL)
            travel=travel->right;
        else{
            travel->right=newNode;
            break;
        }
   }
   else
   {
       if(travel->left!=NULL)
            travel=travel->left;
        else
         {
           travel->left=newNode;
           break;
         }
   }
 }
}

void bst::display(node *travel)
{
    int subChoice;
    cout<<"\n 1 for PreOrder  \n 2 for InOrder";
    cout<<"\n 3 for PostOrder \n Enter your choice : ";
    cin>>subChoice;
    switch(subChoice)
    {
        case 1:
                preOrder(travel);
                break;
        case 2:
                inOrder(travel);
                break;
        case 3:
                postOrder(travel);
                break;
    }

}


void bst::inOrder(node *travel)
{
        if(travel!=NULL)
            {
                inOrder(travel->left);
                cout<<travel->data<<"\t";
                inOrder(travel->right);
            }
}

void bst::preOrder(node *travel)
{
         if(travel!=NULL)
            {
                cout<<travel->data<<"\t";
                preOrder(travel->left);
                preOrder(travel->right);
            }
}

void bst::postOrder(node *travel)
{
           if(travel!=NULL)
            {
                postOrder(travel->left);
                postOrder(travel->right);
                cout<<travel->data<<"\t";
            }
}
//find minimum value in the BST
int bst::findMinnimum()
{
 node *travel=root;
 while(travel!=NULL)
 {

  if(travel->left==NULL)
        return travel->data;

  travel=travel->left;
 }
}
//Mirror image of BST
void bst::mirror(node* travel)
{
 node *temp;
 if(travel!=NULL)
 {
   temp=travel->left;
   travel->left=travel->right;
   travel->right=temp;

   mirror(travel->left);
   mirror(travel->right);
 }
}

void bst::search(int key,node* root)
{
 node *travel=root;
 while(travel!=NULL)
 {
   if(travel->data==key)
   {
    cout<<"Element found "<<endl;
    break;
   }
   if(travel->data<=key)
        travel=travel->right;
   else
        travel=travel->left;

 }
 if(travel==NULL)
  cout<<"Sorry element not found"<<endl;
}
int bst::maxDepth(node *travel)
{
 if(travel==NULL)
  return 0;
 int lDepth=maxDepth(travel->left);
 int rDepth=maxDepth(travel->right);
 if(lDepth>rDepth)
  return lDepth+1;
 return rDepth+1;
}


int main()
{
 int choice;
 bst obj;
 do{
    cout<<"\n BST Operations :: \n1). insert\n2). display";
    cout<<"\n3). Find the minimum value in the tree";
    cout<<"\n4). Mirror the tree\n5). Find longest path";
    cout<<"\n6). exit"<<endl;
    cout<<"\n Enter choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            int data;
            cin>>data;
            obj.insert(data);
            break;
        case 2:
            obj.display(obj.getRoot());
            break;
        case 3:
            cout<<"\n The minimum value in the tree is: ";
            cout<<obj.findMinnimum()<<endl;
            break;
        case 4:
            cout<<"\n Mirroring Done!!" <<endl;
            obj.mirror(obj.getRoot());
            obj.display(obj.getRoot());
            break;

        case 5:
            cout<<"\n Max depth of the tree is :  ";
            cout<<obj.maxDepth(obj.getRoot())<<endl;
            break;

        case 6:
            cout<<"\n You have Exited successfully  ";
            break;
    }
   }while(choice!=6);
 return 0;
}
