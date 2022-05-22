#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <fstream>


using namespace std;

class Node
{
friend class AVL;

private:
	char word[20];
	char meaning[20];
	Node *left;
	Node *right;
	int ht;
public:
	Node()
	{
	  left=NULL;
	  right=NULL;
	}

	Node(char key[],char mean[])
	{
	  strcpy(word,key);
	  strcpy(meaning,mean);
	  left=NULL;
	  right=NULL;
	}

};

class AVL
{
	private:
		Node *root;

		Node *insert(Node *root,char *data,char *mean);
		Node *delet(Node *T,char *data);
		void  printAscending(Node *root);
		void  printDescending(Node *root);
		int   BF(Node *T);
		int   height(Node *T);
		Node *rotateRight(Node *x);
		Node *rotateLeft(Node *x);
		Node *RR(Node *T);
		Node *LL(Node *T);
		Node *LR(Node *T);
		Node *RL(Node *T);

    public:
		AVL()
		   {
			root=NULL;
		   }
		int isEmpty();
		void insert(char data[],char mean[]);
		void delet(char data[]);
		void update(char *key,char *mean);
		void printAscending();
		void printDescending();
		Node *search(char *key);
};
int AVL::isEmpty()
{
	if(root==NULL)
		return 1;
	return 0;
}


void AVL::insert(char data[],char mean[])
{
	root = insert(root,data,mean);
}

Node *AVL::insert(Node *root,char data[],char mean[])
{
  if(root==NULL)
    {
      root=new Node(data,mean);
    }
    else if(strcmp(data,root->word) < 0)
	{
	  root->left=insert(root->left,data,mean);
	  if(BF(root)==2)
	   {
	     if(strcmp(data,root->left->word) < 0)
			root=LL(root);
	     else
			root=LR(root);
	  }
	}
     else if(strcmp(data,root->word) > 0)
      {
		root->right=insert(root->right,data,mean);
		if(BF(root)==-2)
		{
			if(strcmp(data,root->right->word) > 0 )
				root=RR(root);
			else
				root=RL(root);
		}
      }
      else
		root->ht=height(root);
  return(root);
}


void AVL::delet(char data[])
{
	root = delet(root,data);
}

Node *AVL::delet(Node *T,char data[])
 {
   Node *p;
   if(T==NULL)
      return(0);
   else if(strcmp(data,T->word)>0)
      {
	   T->right=delet(T->right,data);
	   if(BF(T)==2)
	      if(BF(T->left)>=0)
			T=LL(T);
		  else
		    T=LR(T);
      }
      else if(strcmp(data,T->word) < 0)
       {
		T->left=delet(T->left,data);
		if(BF(T)==-2)
			if(BF(T->right)<=0)
				T=RR(T);
			else
				T=RL(T);
       }
       else
	   {
	   if(T->right!=NULL)
	    {
	      p=T->right;
		  while(p->left!=NULL)
			p=p->left;

	      strcpy(T->word, p->word);
	      T->right=delet(T->right,p->word);
		  if(BF(T)==2)
		    if(BF(T->left)>=0)
		       T=LL(T);
			else
		       T=LR(T);
	    }
	    else
			return(T->left);
       }
    T->ht=height(T);
    return(T);
 }

int AVL::height(Node *T)
{
	if (T == NULL)
		return 0;
	else if(T->left == NULL && T->right == NULL)
		return 1;
	else return (max(height(T->left),height(T->right))+1);
}
int max(int a,int b)
{
	if (a>b)
		return a;
	return b;
}
int AVL::BF(Node *T)
{
	int lh,rh;
	lh = height(T->left);
	rh = height(T->right);
	return lh-rh;
}

Node *AVL::rotateLeft(Node *x)
  {
    Node *y;
	cout<<" Rotate Left ";
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
    return(y);
   }

Node *AVL::rotateRight(Node *x)
  {
    Node *y;
	cout<<" Rotate Right ";
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
    return(y);
   }

Node *AVL::LL(Node *T)
 {
	cout<<"\nLL Insertion";
    T=rotateRight(T);
    return(T);
 }

Node *AVL::RR(Node *T)
 {
	cout<<"\nRR Insertion";
    T=rotateLeft(T);
    return(T);
 }

Node *AVL::LR(Node *T)
 {
	 cout<<"\nLR Insertion";
    T->left=rotateLeft(T->left);
    T=rotateRight(T);
    return(T);
 }

Node *AVL::RL(Node *T)
 {
	cout<<"\nRL Insertion ";
    T->right=rotateRight(T->right);
    T=rotateLeft(T);
    return(T);
 }

Node *AVL::search(char key[])
  {
	Node *pos=root;
	 while(pos!=NULL)
	  {
	     if(strcmp(key, pos->word)==0)
			break;
	     else if(strcmp(key,pos->word)<0)
			pos=pos->left;
	     else
			pos=pos->right;
	  }
	if(pos==NULL)
	  {
	     cout<<"\n Value not fount";
	     return NULL;
	  }
	  else
	   {
	      cout<<pos->word<<"="<<pos->meaning;
	      return pos;
	   }
  }

void AVL::update(char key[],char mean[])
 {
   Node *temp=search(key);

    if(temp==NULL)
       cout<< "\n The keyword is not present in the Dictionary.";
     else
       {
		strcpy(temp->meaning,mean);
		cout<<"\n Your new data updated successfully.";
       }
 }

void AVL::printAscending()
{
	printAscending(root);
}

void AVL::printAscending(Node *root)
{
	if(root==NULL)
		return;
	else
	{
		printAscending(root->left);
		cout<<root->word<<"="<<root->meaning<<"\n";
		printAscending(root->right);
	}
}

void AVL::printDescending()
{
	printDescending(root);
}

void AVL::printDescending(Node *root)
{
	if(root==NULL)
		return;
	else
	{
		printDescending(root->right);
		cout<<root->word<<"="<<root->meaning<<"\n";
		printDescending(root->left);
	}
}
int main()
{
	AVL obj;
	char data[20],mean[20];
	int  choice;

	cout<<"\n  CREATION OF AVL TREE";

    do
    {
	cout<<"\n MENU: ";
	cout<<"\n1.Taking i/p from File  \n2.Delete \n3.Search \n4.Update \n5.Display in  Ascending  \n6.Display in  Descending  \n7.Exit";

	cout<<"\nEnter the choice: ";
	cin>>choice;
	switch(choice)
	 {
	  case 1:
	  		  cout<<"\n Enter data :";
	  		  cin>>data;
	  		  cout<<"\n Enter Meaning :";
	  		  cin>>mean;
	  		  obj.insert(data,mean);
              cout<<"\n\n AVLTree created Successfully!!!";
            break;

	case 2:
                cout<<" \n Enter the word:  ";
                cin>>data;
                obj.delet(data);
            break;
	case 3:
                cout<<"\n Enter a word to search: ";
                cin>>data;
                obj.search(data);
            break;
	case 4:
                cout<<"\n Enter a word to update: ";
                cin>>data;
                cout<<"\n Enter a meaning to update: ";
                cin>>mean;
                obj.update(data,mean);
            break;
	case 5:
                cout<<" \n Display in Ascending:\n";
                obj.printAscending();
            break;
	case 6:
                cout<<" \n Display in Ascending:\n";
                obj.printDescending();
            break;
    case 6:
                cout<<" \n You have Successfully LoggedOut\n";
            break;
	default:
                cout<<"\n Select Correct choice::";
            break;
	}
   }while(choice!=7);

    return(0);
}

questions
1.State the properties of B+ tree. Construct a B+ tree of order 5 for the following data :
30, 31, 23, 32, 22, 28, 24, 29, 15, 26, 27, 34, 39, 36
2.Explain the different rotations on splay tree.
3. write a short note on trie tree with example
