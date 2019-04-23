#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class hashc
{

typedef struct hash
{
	long pno;
	char name[20];
	int chain;
}hash;

	hash arr[10];
	public:
	void accept();
	void without_r(int,long,char[]);
	void with_r(int ,long,char[]);
	int hashfun(long);
	void display();
	void chain(int);
};
int hashc :: hashfun(long num)
{
	return num%10;
}
void hashc :: accept()
{
	int h,ch,n,i;
	long num;
 	int ans,flag;
 	char name[20];
	do
	{
		for(i=0;i<10;i++)
		{
			arr[i].pno=-1;
			arr[i].chain=-1;
			strcpy(arr[i].name,"");
		}
		cout<<"\n How many names do you want to enter : ";
		cin>>n;

		cout<<"\n 1. Without replacement with chaining : \n 2. With replacement with chaining";
		cout<<"\n Select the option : ";
		cin>>ch;
		for(i=0;i<n;i++)
		{
			cout<<"\n Enter the Phone No : ";
			cin>>num;
			cout<<"\n Enter Name : ";
			cin>>name;
			h=hashfun(num);
			if(ch==1)
			{
				without_r(h,num,name);
			}
			else
			{
				with_r(h,num,name);
				chain(n);
			}				
		}
			
		display();
		cout<<"\n\n Do you want to continue ... press 1\n";
		cin>>ans;
	}while(ans==1);
}
void hashc :: with_r(int h, long num,char nm[])
{
	int i,flag,k;
	char tn[20];
	flag=1;
       long temp;
	k=h;
	do
	{
		if(arr[k].pno==-1)
		{
			arr[k].pno=num;
			strcpy(arr[k].name,nm);
			flag=0;
		}
		else
		{
			if(hashfun(arr[k].pno)!=k && h==k)
			{
				temp=num;
				num=arr[k].pno;
				arr[k].pno=temp;
				
				strcpy(tn,nm);
				strcpy(nm,arr[k].name);
				strcpy(arr[k].name,tn);
				
			}
			k=(k+1)%10;
		}
	}while(flag);
}
void hashc :: without_r(int h,long num,char nm[])
{
	int i,m,flag,k;
	long temp;
	flag=1;

	k=h;
	m=-1;

	do
	{
		if(arr[k].pno==-1)
		{
			arr[k].pno=num;
			strcpy(arr[k].name,nm);
			if(m!=-1)
				arr[m].chain=k;
			flag=0;
		}
		else
		{
			if(hashfun(arr[k].pno)==h)
				m=k;
			k=(k+1)%10;
		}
	}while(flag);
}
void hashc :: display()
{
	int i;
	cout<<"\n\n Hash Table : \n";
	cout<<"\n Index \t\t Phone No \t\t Name\t\tChain\n";
	for(i=0;i<10;i++)
	{
cout<<i<<" \t\t "<<arr[i].pno<<" \t\t "<<arr[i].name<<"\t\t\t "<<arr[i].chain<<"\n";
	}
}

void hashc :: chain(int n)
{
	int i,j;

	for(i=0;i<10;i++)
	{
	   if(arr[i].pno!=-1)
	    {
	
		for(j=i+1;j<10;j++)
		{
		
				if(arr[j].pno!=-1 && (hashfun(arr[i].pno)==hashfun(arr[j].pno)))
				{
					arr[i].chain=j;
					break;
					//j=n;
				}
				  
		}
	   }
	}
}


int main()
{
	hashc h;
	h.accept();
}