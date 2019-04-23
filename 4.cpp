#include <iostream>
#include <ctype.h>
#define size 20

using namespace std;

class btree
{
public:
	char data;
	btree *left, *right;
};

class exptree
{
	btree *stack[size];
	int top;
public:
	btree *root;
	exptree();
	void create(char exp[]);
	void push(btree *);
	void push1(btree *item, int *top, btree *s[10]);
	
	void inorder(btree *root);
	void preorder(btree *root);
	void postorder(btree *root);

	void nonrecinorder(btree *root);
	void nonrecpreorder(btree *root);
	void nonrecpostorder(btree *root);

	btree *pop();
	void pop1(int *top,btree *s[10],btree **current);
	int stempty1(int);
};

exptree :: exptree()
{
	root = NULL;
	top = -1;
}

void exptree :: create(char exp[])
{
	int pos;
	char ch;
	pos =0;
	ch = exp[pos];
	while(ch != '\0')
	{
		root = new btree;
		root -> left = root -> right = NULL;
		root -> data = ch;
		if(isalpha(ch))
			push(root);
		else if(ch =='+' || ch =='-' || ch =='*' || ch =='/')
		{
			root -> right = pop();
			root -> left = pop();
			push(root);
		}
		else
			cout<<"\nInvalid Character in expression\n";
		pos++;
		ch = exp[pos];
	}
	root = pop();
}

void exptree :: push(btree *node)
{
	if(top +1 >= size)
	cout<<"\nError:Stack is Full\n";
	top++;
	stack[top] = node;
}

btree *exptree :: pop()
{
	btree *node;
	if(top == -1)
		cout<<"\nError: Stack is Empty\n";
	node = stack[top];
	top--;
	return(node);
}

void exptree :: inorder(btree *root)
{
	btree *temp;
	temp = root;
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<" "<<temp->data;
		inorder(temp->right);
	}
}

void exptree :: nonrecinorder(btree *root)
{
	btree *current,*s[10];
	int top1 = -1;
	if(root == NULL)
	{
		cout<<"\nTree is Empty\n";
		return;
	}
	current = root;
	for(;;)
	{
		while(current != NULL)
		{
			push1(current, &top1,s);
			current = current -> left;
		}
		if(! stempty1(top1))
		{
			pop1(&top1,s,&current);
			cout<<" "<<current->data;
			current = current ->right;
		}
		else
			return;
	}
}

void exptree :: preorder(btree *root)
{
	btree *temp;
	temp = root;
	if(temp != NULL)
	{
		cout<<" "<<temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void exptree :: nonrecpreorder(btree *root)
{
	btree *current,*s[10];
	int top1 = -1;
	if(root == NULL)
	{
		cout<<"\nTree is Empty\n";
		return;
	}
	current = root;
	for(;;)
	{
		while(current != NULL)
		{
			cout<<" "<<current->data;
			push1(current, &top1,s);
			current = current -> left;
		}
		if(! stempty1(top1))
		{
			pop1(&top1,s,&current);
			current = current ->right;
		}
		else
			return;
	}
}

void exptree :: postorder(btree *root)
{
	btree *temp;
	temp = root;
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<" "<<temp->data;
	}
}

void exptree :: nonrecpostorder(btree *root)
{  exptree pk;
	struct stack
	{
		btree *element;
		int check;
	}st[10];

	btree *current;
	int top = -1;
	if(root == NULL)
	{
		cout<<"\nTree is Empty\n";
		return;
	}
	current = root;
	for(;;)
	{
		while(current != NULL)
		{
			top++;
			st[top].element = current;
			st[top].check=1;
			current = current -> left;
		}
		while(st[top].check == 0)
		{
			current = st[top].element;
			top--;
			cout<<" "<<current -> data;
			if(stempty1(top))
				return;
		}
		current = st[top].element;
		current = current->right;
		st[top].check=0;
	}
}

void exptree :: push1(btree *item,int *top1,btree *s[])
{
	*top1 = *top1 +1;
	s[*top1] = item;
}

void exptree :: pop1(int *top1,btree *s[],btree **current)
{
	*current = s[(*top1)--];
}

int exptree :: stempty1(int top1)
{
	if(top1 == -1)
		return 1;
	else
		return 0;
}

int main()
{
	char exp[80];
	exptree pk;
	cout<<"\nEnter the postfix Expression\n";
	cin>>exp;
	pk.create(exp);
	cout<<"\nThe Tree is Created.....";

	cout<<"\nTheinorder traversal of it is:\n";
	pk.inorder(pk.root);
	cout<<"\nThe Non Recutsiveinorder traversal of it is:\n";
	pk.nonrecinorder(pk.root);

	cout<<"\nThePreorder traversal of it is:\n";
	pk.preorder(pk.root);
	cout<<"\nThe Non RecutsivePreorder traversal of it is:\n";
	pk.nonrecpreorder(pk.root);

	cout<<"\nThePostorder traversal of it is:\n";
	pk.postorder(pk.root);
	cout<<"\nThe Non RecutsivePostorder traversal of it is:\n";
	pk.nonrecpostorder(pk.root);

	return 0;
}

*************OUTPUT***************

[admin@localhost Documents]$ g++ 4.cpp
[admin@localhost Documents]$ ./a.out

Enter the postfix Expression
AB+CD-/

The Tree is Created.....
Theinorder traversal of it is:
 A + B / C - D
The Non Recutsiveinorder traversal of it is:
 A + B / C - D
ThePreorder traversal of it is:
 / + A B - C D
The Non RecutsivePreorder traversal of it is:
 / + A B - C D
ThePostorder traversal of it is:
 A B + C D - /
The Non RecutsivePostorder traversal of it is:
 A B + C D - /
