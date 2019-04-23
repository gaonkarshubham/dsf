using namespace std;
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct STUDENT
 {
	char name[10];
	int rno;
       char div[10];
 }Rec;
 Rec Records;
class STUDENT_CLASS
{
	int n;
	public:
	//STUDENT_CLASS();
	void Create();
	void Display();
	void Update();
	void Delete();
	void Append();
	int Search(int);
};
void STUDENT_CLASS::Create()
{
	char ch='y';
	ofstream seqfile;
	seqfile.open("STUDENT.DAT",ios::out|ios::binary);

	do
	{
		cout<<"\n Enter Name: ";
		cin>>Records.name;
		cout<<"\n Enter rno: ";
		cin>>Records.rno;
		cout<<"\n Enter Division: ";
		cin>>Records.div;
	       seqfile.write((char*)&Records,sizeof(Records))<<flush;
		cout<<"\nDo you want to add more records?";
		cin>>ch;

	}while(ch=='y'|| ch=='Y');

	seqfile.close();

}

void STUDENT_CLASS::Display()
{
	int i,j;
	ifstream seqfile;
		seqfile.open("STUDENT.DAT",ios::in|ios::binary);
		seqfile.seekg(0,ios::beg);

		cout<<"\n The Contents of file are ..."<<endl;
		i=0;

		while(seqfile.read((char *)&Records,sizeof(Records)))
		{

			if(Records.rno!=-1)
			{
					cout<<"\nName: "<<Records.name<<flush;
					cout<<"\nrno: "<<Records.rno;
					cout<<"\nDivision: "<<Records.div;
					cout<<"\n";
			}

		}
 seqfile.close();

}

void STUDENT_CLASS::Update()
{
	ifstream seqfile;
	int pos,id,found;
	char New_name[10];
	int New_rno;
	char New_div[10];

	cout<<"\n For updation,";
	cout<<"\n Enter the rno for for Modification: ";
	cin>>id;

    pos=Search(id);
    
    if(pos!=-1)
    {
		fstream seqfile;
		seqfile.open("STUDENT.DAT",ios::in|ios::out|ios::binary);
	  seqfile.seekg(0,ios::beg);
		cout<<"\n Enter the values for updation...";
		cout<<"\n Name: ";cin>>New_name;
		cout<<"\n Division: ";cin>>New_div;
		int offset=pos*sizeof(Records);
		seqfile.seekp(offset);//seeking the desired record for modification
		strcpy(Records.name,New_name);//can be updated
		Records.rno=id;//It's unique id,so don't change
		strcpy(Records.div,New_div);//can be updated
  	seqfile.write((char*)&Records,sizeof(Records))<<flush;
		cout<<"\n The record is updated!!!";
    }

	seqfile.close();
}

void STUDENT_CLASS::Delete()
	{

      ifstream seqfile;
			int pos,id,found;
			cout<<"\n For Deletion,";
			cout<<"\n Enter the rno for for Deletion: ";
			cin>>id;
	    pos=Search(id);
	    if(pos!=-1)
		    {
					fstream seqfile;
					seqfile.open("STUDENT.DAT",ios::in|ios::out|ios::binary);
					seqfile.seekg(0,ios::beg);
					int offset=pos*sizeof(Records);
					seqfile.seekp(offset);//seeking the desired record for modification
					strcpy(Records.name,"");
					Records.rno=-1; //logical deletion
					strcpy(Records.div,""); //logical deletion
					seqfile.write((char*)&Records,sizeof(Records))<<flush;
					cout<<"\n The record is Deleted!!!";
		    }
			seqfile.close();

	}

void STUDENT_CLASS::Append()
{
		ofstream seqfile;
		seqfile.open("STUDENT.DAT",ios::app|ios::binary);
		cout<<"\n Enter the record for appending";
		cout<<"\nName: ";cin>>Records.name;
		cout<<"\nrno: ";cin>>Records.rno;
		cout<<"\nDivision: ";cin>>Records.div;
		seqfile.write((char*)&Records,sizeof(Records));//inserting rec at end in seq. file
		seqfile.close();
		cout<<"\n The record is Appended!!!";
}

int STUDENT_CLASS::Search(int id)
{

	fstream seqfile;
	int i,pos=0,offset,found;
	seqfile.open("STUDENT.DAT",ios::in|ios::binary);
	seqfile.seekg(0,ios::beg);
	found=0;
	while(!found && seqfile.read((char *)&Records,sizeof(Records)))
			{
				if(id==Records.rno)//the desired record is found
						{
							cout<<"\nRecord Found...Details are\n";
							cout<<"\n Name: "<<Records.name;
							cout<<"\n rno: "<<Records.rno;
							cout<<"\n Division: "<<Records.div;
							found=1;
							return pos;
							//break;
						}
						//else
							pos++;
			}
	if(found==0)
		{
			cout<<"\nRecord Not Present\n";
			return -1;
		}
	seqfile.close();
}

int main()
	{
		STUDENT_CLASS List;
		char ans='y';
		int choice,key;
		do
			{
				system("clear");
				cout<<"\n             Main Menu             "<<endl;
				cout<<"\n 1.Create";
				cout<<"\n 2.Display";
				cout<<"\n 3.Update";
				cout<<"\n 4.Delete";
				cout<<"\n 5.Append";
				cout<<"\n 6.Search";
				cout<<"\n 7.Exit";
				cout<<"\n Enter your choice: ";
				cin>>choice;
				switch(choice)	
					{
						case 1:List.Create();
									break;

						case 2:List.Display();
									break;

						case 3:List.Update();
									break;

						case 4:List.Delete();
									break;

						case 5:List.Append();
									break;

						case 6:
									cout<<"\nEnter emp-id : ";
									cin>>key;
									List.Search(key);
									break;

						case 7:exit(0);

					}

				cout<<"\n\t Do you want to go back to Main Menu?";
				cin>>ans;
			}while(ans=='y');
	}
