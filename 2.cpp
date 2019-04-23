#include<iostream>
#include<cstring>
#include<math.h>
#include<ctype.h>
using namespace std;
class node
{
public:
	char data[20];
	node *next;
	int p;
	node()
	{
	next=NULL;
	}
	node(char item[20], int PP)
	{
	strcpy(data,item);
	p=PP;
	next=NULL;
	}
};

class pqueue
{public:
	node *front;

	pqueue()
	{
	front=NULL;
	}

	int isempty()
	{
		if(front==NULL) return 1;
		else return 0;
	}
	void enqueue(char n[],int pri)
	{
	node *temp=new node(n,pri);
	node *t;
	t=front;
		if(isempty())
		{
			front=temp;			
		}
		else if(t->next==NULL && pri < t->p)
		{
			temp->next=front;
			front=temp;
		}
		else if(t->next==NULL && pri >= t->p)
		{
			front->next=temp;
		}		
		else
		{	
			whi[admin@localhost Documents]$ g++ 2.cpp
le(t->next!=NULL)	
			{if(pri>=t->next->p)			
				t=t->next;
			 else break;
			}
			temp->next=t->next;
			t->next=temp;		
		}
	}
	
	void dequeue()
	{
	node *temp;
	temp=front;
		if(isempty())
		{
		cout<<"Error: Queue is empty...\n";
		return;	
		}
		else if(front->next==NULL)
		{
		front=NULL;
		delete temp;
		}
		else
		{
		front=front->next;
		delete temp;
		}
	cout<<"\nPatient deleted...";
	}

	void print()
	{
	node *temp;
	temp=front;
	if(temp==NULL)
	{cout<<"\nQueue is Empty...";
	return;
	}
	cout<<"\nThe Queue is:";
	while(temp!=NULL)
	{
	cout<<"\n  "<<temp->data<<" "<<temp->p;
	temp=temp->next;
	}
	cout<<"\n";
	}
};


int main()
{
pqueue p;
char name[20];
int pri;
int ch;
do{

cout<<"\n1.Enter Patient\n2.Delete Patient\n3.Display Patient Queue\n4.Exit";
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1:
	cout<<"Enter Patient name:";
	cin>>name;
	cout<<"Enter Priority:";
	cin>>pri;
	p.enqueue(name,pri);
	break;
case 2:
	p.dequeue();
	break;
case 3:
	p.print();
	break;
}
}while(ch!=4);

return 0;
}


*************OUTPUT***************

[admin@localhost Documents]$ g++ 2.cpp
[admin@localhost Documents]$ ./a.out

1.Enter Patient
2.Delete Patient
3.Display Patient Queue
4.Exit
Enter your choice:1
Enter Patient name:K  
Enter Priority:2

1.Enter Patient
2.Delete Patient
3.Display Patient Queue
4.Exit
Enter your choice:1
Enter Patient name:C
Enter Priority:1

1.Enter Patient
2.Delete Patient
3.Display Patient Queue
4.Exit
Enter your choice:1
Enter Patient name:S
Enter Priority:3

1.Enter Patient
2.Delete Patient
3.Display Patient Queue
4.Exit
Enter your choice:3

The Queue is:
  C 1
  K 2
  S 3

1.Enter Patient
2.Delete Patient
3.Display Patient Queue
4.Exit
Enter your choice:2

Patient deleted...
1.Enter Patient
2.Delete Patient
3.Display Patient Queue
4.Exit
Enter your choice:3

The Queue is:
  K 2
  S 3

1.Enter Patient
2.Delete Patient
3.Display Patient Queue
4.Exit
Enter your choice:4

