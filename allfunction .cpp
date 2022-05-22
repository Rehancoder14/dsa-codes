/* Implement all the functions of a dictionary (ADT)
using hashing. Data: Set of (key, value) pairs,
Keys are mapped to values, Keys must be comparable,
Keys must be unique Standard Operations:
Insert(key, value), Find(key), Delete(key)
*/
#include<iostream>
#include<string.h>
#define TABLESIZE 10
using namespace std;
class Node
{
  public:
	int  data;
	char word[20];
	char mean[30];
	Node *next;

	Node(){
		data=0;
		strcpy(word,"-");
		strcpy(mean,"-");
		next=NULL;
	}
};
class SeperateChaining
{
	public:
	    Node *hashTable[TABLESIZE];
        SeperateChaining(){
            for(int i=0;i<TABLESIZE;i++){
                hashTable[i]=new Node();
                hashTable[i]->data=i;
            }
        }
        int hashFunction(char newWord[]);
        void insertWord(char newWord[],char newMean[]);
        void display();
        void searchWord(char key[]);
        void deleteWord(char key[]);
};
int SeperateChaining::hashFunction(char newWord[])
{
	int sum=0;
	for(int i=0;newWord[i]!='\0';i++){
		int a=newWord[i];
		sum+=a;
	}
	return sum%TABLESIZE;
}
void SeperateChaining::insertWord(char newWord[],char newMean[])
{
	int position=hashFunction(newWord);
	Node *temp,*pnew;

	pnew=new Node();
    strcpy(pnew->word,newWord);
	strcpy(pnew->mean,newMean);
	pnew->next=NULL;

	temp=hashTable[position];
	while(temp->next!=NULL)
        temp=temp->next;

	temp->next=pnew;
}
void SeperateChaining::display(){
	Node *temp;
	for(int i=0;i<10;i++){
		temp=hashTable[i];
		cout<<temp->data<<" ";
		temp=temp->next;
		while(temp!=NULL){
			cout<<temp->word<<" = "<<temp->mean<<" -> ";
			temp=temp->next;
		}
		cout<<"\n";
	}
}
void SeperateChaining::searchWord(char key[])
{
	int position=hashFunction(key);
	Node *temp;
	temp=hashTable[position];
	while(temp->next!=NULL){
		if(strcmp(temp->word,key)!=0)
			temp=temp->next;
        else
            break;
	}
	if(strcmp(temp->word,key)==0)
	{
        cout<<"Word: "<<temp->word;
        cout<<"=\t "<<temp->mean;
	}
	else
		cout<<"Word not present!";
}
void SeperateChaining::deleteWord(char key[])
{
	int position=hashFunction(key);
	Node *prev,*current;
	prev=hashTable[position];
	current=hashTable[position]->next;
	while((current->next!=NULL)&&(strcmp(current->word,key)!=0)){
		prev=current;
		current=current->next;
	}
	prev->next=current->next;
	cout<<"\nWord was deleted successfully!";
}
int main()
{
	SeperateChaining sOb;
	int choice;
	char newWord[20],newMean[30],key[20];
	do
	{
		cout<<"\n\n1)Insert word in dictionary\n2)Display\n3)Search word\n4)Delete word\n5)Exit\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			    cout<<"\nEnter word: ";
				cin>>newWord;
				cout<<"Enter meaning of word: ";
				cin>>newMean;
				sOb.insertWord(newWord,newMean);
				break;
            case 2:
                sOb.display();
				break;
			case 3:
			    cout<<"\nEnter the word: ";
				cin>>key;
				sOb.searchWord(key);
				break;
			case 4: cout<<"\nEnter the word: ";
				cin>>key;
				sOb.deleteWord(key);
				break;
			case 5:
			    return 0;
			default:
			    cout<<"\nWrong choice!";
		}
	}while(choice!=5);
	return 0;
}
















#include<iostream>
using namespace std;
int main()
{
	
	char newWord[20],newMean[30],key[20];
	cout<<"\nEnter word: ";
				cin>>newWord;
				cout<<"Enter meaning of word: ";
				cin>>newMean;
				int sum=0;
	for(int i=0;newWord[i]!='\0';i++){
		int a=newWord[i];
		sum+=a;
	}
	int loc= sum%10;
	cout<<"location is"<<loc;
	return 0;
}



























