


#include<iostream>
#include<string.h>
#define tableSize 10
using namespace std;
class Node
{
  public:
	int tId;
	char tNo[11];
	char tAdd[10];
	char tName[10];
	Node(){
		tId=0;
		strcpy(tNo,"-");
		strcpy(tName,"-");
		strcpy(tAdd,"-");
	}
};
class LinearProbing
{
	Node hashTable[10];
	int totalCount;
	int hashFunction(int key);
	public:
	LinearProbing()
	{
		totalCount=0;
	}

	void insertData(char[],int,char[],char[]);
	void findData(int);
	void display();
	void deleteData(int);
};
int LinearProbing::hashFunction(int key)
{
	return key%tableSize; //key%TableSize
}

void LinearProbing::insertData(char name[],int id,char no[],char add[])
{
	if(totalCount==tableSize)
	{
		cout<<"\nOverflow! Cannot insert!";
		return;
	}
	int bucketAddress,position,i=0,cnt=0;
	position=hashFunction(id);
	do{
		bucketAddress=(position+i)%tableSize;
		i++;
		cnt++;
	}while((hashTable[bucketAddress].tId!=0)&&(cnt<10));

	hashTable[bucketAddress].tId=id;
	strcpy(hashTable[bucketAddress].tNo,no);
	strcpy(hashTable[bucketAddress].tName,name);
	strcpy(hashTable[bucketAddress].tAdd,add);
	totalCount++;
}

void LinearProbing::findData(int key)
{
	int bucketAddress,position,i=0,cnt=0;
	position=hashFunction(key);
	do{
        bucketAddress=(position+i)%10;
		i++;
		cnt++;
	}while((hashTable[bucketAddress].tId!=key)&&(cnt<10));
	if(hashTable[bucketAddress].tId!=key)
        cout<<"\nUser is not present!";
	else{
		cout<<"\nName: "<<hashTable[bucketAddress].tName;
		cout<<"\nUser ID: "<<hashTable[bucketAddress].tId;
		cout<<"\nUser number: "<<hashTable[bucketAddress].tNo;
		cout<<"\nUser Address: "<<hashTable[bucketAddress].tAdd;
	}
}
void LinearProbing::deleteData(int id)
{
	int bucketAddress,position,i=0,cnt=0;
	char ch;
	position=hashFunction(id);
	do
	{
		bucketAddress=(position+i)%tableSize;
		i++;
		cnt++;
		cout<<"Do you want to delete user "<<hashTable[bucketAddress].tName<<"? (y/n): ";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
			hashTable[bucketAddress].tId=0;
			strcpy(hashTable[bucketAddress].tNo,"-");
			strcpy(hashTable[bucketAddress].tName,"-");
			strcpy(hashTable[bucketAddress].tAdd,"-");
			cout<<"\nSuccessfully deleted!";
			totalCount--;
			break;
		}
	}while((hashTable[bucketAddress].tId!=0)&&(cnt<10));
}
void LinearProbing::display()
{
	cout<<"\nName\t\tID\t\tNumber\t\tAdress\n";
	for(int i=0;i<10;i++)
	{
		cout<<hashTable[i].tName<<"\t\t"<<hashTable[i].tId<<"\t\t"<<hashTable[i].tNo<<"\t\t"<<hashTable[i].tAdd<<"\n";
	}
}
int main()
{
	char name[10],add[10],no[10];
	LinearProbing lObj;
	int choice,id,key;

	do
	{
		cout<<"\n\n1)Insert\n2)Display\n3)Search\n4)Delete\n5)Exit\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			    cout<<"Enter user name: "; 	        cin>>name;
				cout<<"Enter user ID: ";		    cin>>id;
				cout<<"Enter user telephne no.: ";	cin>>no;
				cout<<"Enter user address: ";		cin>>add;
				lObj.insertData(name,id,no,add);
				break;

			case 2:
			    lObj.display();
				break;

			case 3:
			    cout<<"\nEnter the user ID of the user: "; cin>>key;
				lObj.findData(key);
				break;

			case 4:
			    cout<<"\nEnter the user ID of the user: ";  cin>>key;
				lObj.deleteData(key);
				break;

			case 5: return 0;
                default:cout<<"Wrong choice!";
		}
	}while(choice!=5);
	return 0;
}





Questions EXP-1


1. Whats is hashing? Explain in detail.
2. What is collision ? which are the different methos to hdle collision.Explain any one with example
3. Compare the Open hashing and closed hasing
4. define the terms
       Synonyms
       Bucket
       Home adress
Prime area
Overflow











































