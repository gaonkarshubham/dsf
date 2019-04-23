#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node *left,*right;
	node()
	{
	left=right=NULL;	
	}

};

class bintree
{
public:
	node *root;

	bintree()
	{
		root = NULL;
	}
	node* create();
	void display();
	void inorder(node *);
	int depth(node *);
	node* copytree(node *T);
	void leafdisplay(node *T);
};	

node* bintree :: create()
{
	node *New;
	int x;
		
	cout<<"\nEnter the Element:(-1 for no data):";
	cin>>x;
	if(x!=-1)
	{
	New = new node;
	New->data=x;
	cout<<"Enter Left child of "<<x<<" :";
	New->left=create();	
	cout<<"Enter Right child of "<<x<<" :";
	New->right=create();		
	root=New;	
	return(New);
	}
	else	return(NULL);
}

void bintree :: display()
{
	if(root == NULL)
		cout<<"\nTree Is Not Created....";
	else
	{
		cout<<"\nThe Tree is:";
		inorder(root);
	}
}

void bintree :: inorder(node *temp)
{
	if(temp != NULL)
	{
		inorder(temp -> left);
		cout<<" "<<temp->data;
		inorder(temp->right);
	}
}

int bintree :: depth(node *T)
{
	int hl,hr;
	if(T==NULL)	return 0;
	if(T->left==NULL && T->right==NULL)	return 0;
	hl=depth(T->left);
	hr=depth(T->right);
	if(hl>hr)	return(hl+1);
	return(hr+1);
}

void bintree :: leafdisplay(node *T)
	{
	if(T==NULL) return;
	else if(T->left == NULL && T->right == NULL)
	cout<<" "<<T->data;
	leafdisplay(T->left);
	leafdisplay(T->right);
	}


node* bintree :: copytree(node *T)
	{
	node *P;
	P=NULL;
		if(T!=NULL)
		{
		P=new node();
		P->data=T->data;
		P->left=copytree(T->left);
		P->right=copytree(T->right);		
		}
	return(P);
	}

int main()
{
	int choice;
	char ans;
	bintree pk;
	do
	{	
		cout<<"\n1.Create \n2.Display \n3.Depth \n4.Display Leaf Nodes \n5.Copy Tree \n6.Exit";
		cout<<"\nEnter Your Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				pk.create();
				break;
			case 2:
				pk.display();
				break;
			
			case 3:
				cout<<"\nThe depth of the tree is: ";				
				cout<<pk.depth(pk.root);
				break;
			case 4:
				cout<<"The leaf nodes are: ";				
				pk.leafdisplay(pk.root);
				break;
			case 5:
				cout<<"The copy of tree is:";
				pk.copytree(pk.root);
				pk.display();
				break;
		}
	}while(choice != 6);
	return 0;
}

*************OUTPUT***************
[admin@localhost Documents]$ g++ 3.cpp
[admin@localhost Documents]$ ./a.out

1.Create 
2.Display 
3.Depth 
4.Display Leaf Nodes 
5.Copy Tree 
6.Exit
Enter Your Choice:1

Enter the Element:(-1 for no data):1
Enter Left child of 1 :
Enter the Element:(-1 for no data):2
Enter Left child of 2 :
Enter the Element:(-1 for no data):2
Enter Left child of 2 :
Enter the Element:(-1 for no data):^C
[admin@localhost Documents]$ ./a.out

1.Create 
2.Display 
3.Depth 
4.Display Leaf Nodes 
5.Copy Tree 
6.Exit
Enter Your Choice:1

Enter the Element:(-1 for no data):5
Enter Left child of 5 :
Enter the Element:(-1 for no data):4
Enter Left child of 4 :
Enter the Element:(-1 for no data):3
Enter Left child of 3 :
Enter the Element:(-1 for no data):-1
Enter Right child of 3 :
Enter the Element:(-1 for no data):-1
Enter Right child of 4 :
Enter the Element:(-1 for no data):5
Enter Left child of 5 :
Enter the Element:(-1 for no data):-1
Enter Right child of 5 :
Enter the Element:(-1 for no data):4
Enter Left child of 4 :
Enter the Element:(-1 for no data):-1
Enter Right child of 4 :
Enter the Element:(-1 for no data):-1
Enter Right child of 5 :
Enter the Element:(-1 for no data):2
Enter Left child of 2 :
Enter the Element:(-1 for no data):-1
Enter Right child of 2 :
Enter the Element:(-1 for no data):-1

1.Create 
2.Display 
3.Depth 
4.Display Leaf Nodes 
5.Copy Tree 
6.Exit
Enter Your Choice:2

The Tree is: 3 4 5 4 5 2
1.Create 
2.Display 
3.Depth 
4.Display Leaf Nodes 
5.Copy Tree 
6.Exit
Enter Your Choice:3

The depth of the tree is: 3
1.Create 
2.Display 
3.Depth 
4.Display Leaf Nodes 
5.Copy Tree 
6.Exit
Enter Your Choice:4
The leaf nodes are:  3 4 2
1.Create 
2.Display 
3.Depth 
4.Display Leaf Nodes 
5.Copy Tree 
6.Exit
Enter Your Choice:5
The copy of tree is:
The Tree is: 3 4 5 4 5 2
1.Create 
2.Display 
3.Depth 
4.Display Leaf Nodes 
5.Copy Tree 
6.Exit
Enter Your Choice:6



