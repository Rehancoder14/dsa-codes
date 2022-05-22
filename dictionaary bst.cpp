#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class node
{
	private:
		node *left,*right;
		string keyword,meaning;
	public:
		node()
		{
			left=right=NULL;
			keyword=meaning='\0';
		}
		friend class bst;
};

class bst
{
	public:
		node *root;
		bst()
		{
			root=NULL;
		}
		node* getRoot()
		{
			return root;
		}
		void insert(string,string);
		void inOrder(node *);
		void search(string,node *);
		void update(string,string,string,node *);
		void delet(string,node *);
		void reverse(node *);
};

//Inserting a node into BST
void bst::insert(string key,string mean)
{
	node *newNode=new node();
	newNode->keyword=key;
	newNode->meaning=mean;
	node *travel=root;
	if(root==NULL)
		root=newNode;
	while(travel!=NULL)
	{
		if(key > travel->keyword)
		{
			if(travel->right!=NULL)
				travel=travel->right;
			else
			{
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
	cout<<"inserted\n";
}

void bst::inOrder(node *travel)
{
	if(travel!=NULL)
	{
		inOrder(travel->left);
		cout<<travel->keyword<<"( "<<travel->meaning<<")\t";
		inOrder(travel->right);
	}
}

void bst::reverse(node *travel)
{
	if(travel!=NULL)
	{
		inOrder(travel->right);
		cout<<travel->keyword<<"( "<<travel->meaning<<")\t";
		inOrder(travel->left);
	}
}

void bst::search(string key,node *root)
{
	node *travel=root;
	while(travel!=NULL)
	{
		if(travel->keyword==key)
		{
			cout<<"\nKeyword is Present\n";
			break;
		}
			if(travel->keyword >= key)
				travel=travel->left;
			else
				travel=travel->right;

	}
	if(travel==NULL)
						cout<<"\nKeyword is not Present\n";
}

void bst::update(string key,string key1,string mean,node *root)
{
	node *travel=root;
	while(travel!=NULL)
	{
		if(travel->keyword==key)
		{
			cout<<"\nKeyword is Present\n";
			travel->keyword=key1;
			travel->meaning=mean;
			break;
		}
			if(travel->keyword >= key)
				travel=travel->left;
			else
				travel=travel->right;

	}
	if(travel==NULL)
						cout<<"\nKeyword is not Present\n";
}

void bst::delet(string key1,node *root)
{
	node *temp=root;
	node *parent=root;
	node *temp_succ;
		while(temp!=NULL)
		{
			if(temp->keyword==key1)
			{

				if(temp->left==NULL && temp->right==NULL)	//leaf node deletion
				{
					if(temp==root)
						root=NULL;

					else if(parent->left==temp)
						parent->left=NULL;

					else if(parent->right==temp)
						parent->right=NULL;

					delete temp;
					cout<<"\n deletion completed\n";
				}

			else if(temp->left!=NULL && temp->right==NULL)	//deletion of node having left child but no right child
				{
					if(parent->left==temp)
						parent->left=temp->left;

					else
						parent->right=temp->left;

					delete temp;
					cout<<"\n node has deleted\n";
					return;
				}

			else if(temp->left==NULL && temp->right!=NULL)	//deletion of node having right child but no left child
				{
					if(parent->right==temp)
							parent->right=temp->right;

					else
							parent->left=temp->right;

						delete temp;
						cout<<"\n node has deleted\n";
						temp=NULL;
						return;
				}

			else if(temp->left!=NULL && temp->right!=NULL)	//deletion of node having two child
				{
						parent=temp;
						temp_succ=temp->right;
						while(temp_succ->left!=NULL)
						{
							parent=temp_succ;
							temp_succ=temp_succ->left;
						}
				temp->keyword=temp_succ->keyword;
					temp->meaning=temp_succ->meaning;
						parent->right=NULL;
				delet(temp_succ->keyword,temp->right);
				}

				break;
			}

			if(temp->keyword >= key1)
			{
					parent=temp;
					temp=temp->left;
			}

			else
			{
					parent=temp;
					temp=temp->right;
			}

		}
		if(temp==NULL)
					cout<<"\nKeyword is not Present\n";
}

int main() {

	bst bt;
		int ch;
		string key,mean,key1,Newkey,mean1;
		do
		{
			cout<<"\n\n***************** MENU *****************\n";
			cout<<"\n1.Insert a Keyword";
			cout<<"\n2.Display";
			cout<<"\n3.Search a Keyword";
			cout<<"\n4.Delete a Keyword";
			cout<<"\n5.Update any Keyword";
			cout<<"\n6.Exit";
			cout<<"\n\nEnter Your Choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"\nEnter keyword to insert : ";
					cin>>key;
					cout<<"\nEnter meaning of that keyword : ";
					cin>>mean;
					bt.insert(key,mean);
					break;

				case 2:
					bt.inOrder(bt.root);
					break;

				case 3:
					cout<<"\nEnter Keyword to search : ";
					cin>>key1;
					bt.search(key1,bt.root);
					break;

				case 4:
					cout<<"\nEnter Keyword to delete : ";
					cin>>key1;
					bt.delet(key1,bt.root);
					break;

				case 5:
					cout<<"\nWhich keyword you want to update :";
					cin>>key;
					cout<<"\nEnter new keyword : ";
					cin>>Newkey;
					cout<<"\nEnter meaning of that new keyword : ";
					cin>>mean1;
					bt.update(key,Newkey,mean1,bt.root);
					break;

				case 6:
					exit(1);

				default:
					cout<<"\nEnter valid choice\n";
			}
		}while(ch<7);
	return 0;
}

QUESTIONS
1.Explain how to convert general tree to Binary tree WITH EXAMPLE
2.Write a function to search AND DELETE an element in BST .
3.Define skewed, full and complete binary tree with examples.





