/*Department maintains a student information.
The file contains roll number, name, division and address.
Allow user to add, delete information of student.
Display information of particular employee.
If record of student does not exist an appropriate message is displayed.
If it is, then the system displays the student details.
Use sequential file to maintain the data. */

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
#define max 100
class student
{
private :
	char name[10];
	char address[10];
	char roll[5];
	char clas[5];
	char div[5];
	char buff[max];

public:

	void pack()
	{
		strcpy(buff,roll);
		strcat(buff,"|");
		strcat(buff,name);
		strcat(buff,"|");
		strcat(buff,clas);
		strcat(buff,"|");
		strcat(buff,div);
		strcat(buff,"|");
		strcat(buff,address);
		strcat(buff,"#");
		//cout<<" \n Pack Buffer = "<<buff;
	}

	void unpack()
	{
		strcpy(roll,strtok(buff,"|"));
		strcpy(name,strtok(NULL,"|"));
		strcpy(clas,strtok(NULL,"|"));
		strcpy(div,strtok(NULL,"|"));
		strcpy(address,strtok(NULL,"#"));
		//cout<<" \n UnPack Buffer = "<<buff <<"\n";
	}

	void add()
	{
		cout<<"\nEnter Roll number : ";
		cin>>roll;
		cout<<"\nEnter Name : ";
		cin>>name;
		cout<<"\nEnter Class : ";
		cin>>clas;
		cout<<"\nEnter Div : ";
		cin>>div;
		cout<<"\nEnter Address : ";
		cin>>address;

		pack();

		ofstream out;
		out.open("student",ios::app);
		out<<buff<<endl;
		out.close();
		cout<<"\nSuccessfully added!"<<endl;
	}

	void display()
	{

		ifstream fin;
		fin.open("student");
		cout<<"\n\n************Student Record************ \n\n";
		cout<<"Roll \tName \tClass \tDiv \tAddress "<<endl;

		while(!fin.eof())
		{
			fin>>buff;
			if(fin.fail( ))
		        break;
			unpack();
			cout<<roll<<" \t"<<name<<" \t"<<clas<<" \t"<<div<<" \t"<<address<<endl;
		}
		fin.close();


	}

	void search()
	{
		char key[5];
		cout<<"\nEnter roll number of record to be Searched : ";
		cin>>key;
		ifstream in;
		in.open("student");
		while(!in.eof())
		{
			in>>buff;
			unpack();
			if(strcmp(roll,key)==0)
			{
				cout<<"\nRecord Found !";
				cout<<"\nDetails are : "<<endl;
				cout<<"\nName     : "<<name;
				cout<<"\nRoll     : "<<roll;
				cout<<"\nClass    : "<<clas;
				cout<<"\nDIv      : "<<div;
				cout<<"\nAddress  : "<<address;
				in.close();
				return;
			}
		}
		cout<<"\nRecord not Found! ";
	}

	void deleterec()
	{
		char key[5];
		cout<<"\nEnter roll number of record to be Deleted : ";
		cin>>key;

		ifstream file;
		file.open("student");
		ofstream out;
		out.open("temp",ios::app);
		while(!file.eof())
		{
			file>>buff;
			if(file.fail( ))
		        break;
			unpack();

			if(strcmp(key,roll)==0)
			{
                    pack();
                    cout<<"\n Record   deleted  with details :  "<<buff<<"\n";
			}
			else{
                        pack();
                        out<<buff<<endl;
				}
		}
		file.close();
		out.close();
		remove("student");
		rename("temp","student");



	}
	void modify()
	{
	}
};

int main()
{
student s;
int op=-1;

while(op!=0)
{
	cout<<"\n1.Add";
	cout<<"\n2.Display";
	cout<<"\n3.Search";
	cout<<"\n4.Delete";
	cout<<"\n5.Update";
	cout<<"\n0.Exit";
	cout<<"\n\nEnter your choice  : ";
	cin>>op;
	switch(op)
	{
			case 1:
                                s.add();
                                break;
                        case 2:
                                s.display();
                                break;
                        case 3:
                                s.search();
                                break;
                        case 4:
                               s.deleterec();
                                break;
                        case 5:
                        	s.modify();
                                break;
                        default:
                                cout<<"Wrong choice!";
	}
}

return 0;
}
Questiond
1.Compare sequential and indexed sequential files
2.What is direct access file ? Write pseudo-code for performing primitive operation on direct access file
3. Explain different modes of opening files.