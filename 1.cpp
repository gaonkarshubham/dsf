#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

class node
{
public:
	double data;
	node *next;
	node()
	{
		next = NULL;
	}
	node(double item)
	{
		next = NULL;
		data = item;
	}
};

class stack
{
	node *top;
public:
	stack()
	{
		top = NULL;
	}

	int stempty()
	{
		if(top == NULL)
				return 1;
		return 0;
	}
	double pop()
	{
		if(stempty())
		{
			std::cout<<"\nError:Stack is Empty";
			return -1;
		}
		else
		{
			node *temp = top;
			top = top -> next;
			double item = temp -> data;
			delete temp;
			return item;
		}

	}

	void push(double item)
	{
		node *temp=new node(item);
		temp->next = top;
		top = temp;
	}

	void postfix(char exp[40], char post[40]);

	~stack();

	double eval(char exp[])
	{
		char ch;
		char type[20];
		double result;
		double val,op1,op2;
		int i=0;
		ch = exp[i];
		while(ch !='\0')
		{
			if(ch>='0' &&ch<='9')
				strcpy(type,"operand");
			else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
				strcpy(type,"operator");
			if(strcmp(type,"operand")==0)
			{
				val = ch -48;
				push(val);
			}
			else if(strcmp(type,"operator")==0)
			{
				op2=pop();
				op1=pop();
				switch(ch)
				{
					case '+':result=op1+op2;
					break;
					case '-':result=op1-op2;
					break;
					case '*':result=op1*op2;
					break;
					case '/':result=op1/op2;
					break;
					case '^':result = pow(op1,op2);
					break;
				}
				push(result);
			}
			i++;
			ch = exp[i];
		}
		result=pop();
		return(result);
	}

	void prefix(char a[40], char pre[40])
	{	int length;
		strrev(a);
		length=strlen(a);
		for(int i=0;i<length;i++)
		{

			if(a[i]=='(')
			{
				a[i]=')';
			}
			else if(a[i]==')')
			{
				a[i]='(';
			}
		}
		postfix(a,pre);
		strrev(pre);
	}


	void strrev(char *str)
	{
		int i,j;
		char temp;
		j = strlen(str) -1;
		for (i = 0; i < j; i++,j--)
		{
			temp = str[i];
		        str[i] = str[j];
		        str[j] = temp;
		}
	}
};

void stack :: postfix(char exp[40],char post[40])
{
	int length,j;
	char ch;

	j=0;
	length=strlen(exp);

	for(int i=0;i<length;i++)
	{
		ch = exp[i];
		if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
			push(ch);
		else if(ch != ')')
		{
			post[j]=ch;
			j++;
		}
		else
		{
			do
			{
				ch =pop();
				if(ch != '(')
				{
					post[j]=ch;
					j++;
				}
			}while(ch != '(');
		}
	}
	while(!stempty())
	{
		ch=pop();
		if(ch != '(')
		{
			post[j]=ch;
			j++;
		}
	}
	post[j] = '\0';
}

stack :: ~stack()
{
	node *temp=top;
	while(top != NULL)
	{
		top = top -> next;
		delete temp;
		temp = top;
	}
}

int main()
{
	char in[40],pre[40],post[40];
	stack pk;
	std::cout<<"\n Enter Parenthsized Infix Expression:  ";
	std::cin>>in;
	pk.postfix(in,post);
	std::cout<<"\n\nPostfix="<<post;
	std::cout<<"\n\nEvaluation="<<pk.eval(post);
	pk.prefix(in,pre);
	std::cout<<"\n\nPrefix="<<pre<<"\n";
	return 0;
}

/************OUTPUT***************

[admin@localhost Documents]$ g++ 1.cpp
[admin@localhost Documents]$ ./a.out


Enter Parenthsized Infix Expression:  (A+B)/(C-D)


Postfix=AB+CD-/

Evaluation=-1

Prefix=/+AB-CD
*/
