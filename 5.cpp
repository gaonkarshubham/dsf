#include<iostream>
#include<queue>
using namespace std;

typedef struct node
	{
		int data;
		struct node *left,*right;
	}node;


class bintree
{
public:
	
	node *root,*New,*temp;

	bintree()
	{
		root = NULL;
	}
	void create();
	void display();
	void delet();
	void find();
	void insert(node *,node *);
	void inorder(node *);
	void search(node **,int);
	//void del(node *,int,node *);
	void mirror(node *root);
	node * Delet(node *,int);
	node* FindMin(node *n);
	void BFS(node *);
};

void bintree :: create()
{
	New = new node;
	New -> left = NULL;
	New -> right = NULL;
	cout<<"\nEnter the Element:";
	cin>>New->data;
	if(root == NULL)
		root = New;
	else
		insert(root,New);
}

void bintree :: insert(node *root,node *New)
{
	if(New -> data < root -> data)
	{
		if(root -> left == NULL)
			root->left=New;
		else
			insert(root -> left,New);
	}
	if(New -> data > root ->data)
	{
		if(root -> right == NULL)
			root -> right = New;
		else
			insert(root->right,New);
	}
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

void bintree :: find()
{
	int key;
	cout<<"\nEnter the Element Which You Want To Search:";
	cin>>key;
	temp = root;
	search(&temp,key);
	if(temp == NULL)
		cout<<"\nElement is NOT Present";
}

void bintree :: search(node **temp,int key)
{
	if(*temp == NULL)
	cout<<"Tree is Not Created";
	else
	{
		while(*temp != NULL)
		{
			if((*temp)->data == key)
			{
				cout<<"\nThe "<<(*temp)->data<<" Element is Present";
				break;
			}
			if((*temp)->data > key)
				*temp= (*temp)->left;
			else
				*temp = (*temp)->right;
		}
	}
	return;
}

void bintree :: delet()
{
	int key;
	cout<<"\nEnter the Element You wish to Delete:";
	cin>>key;
	root=Delet(root,key);
}





node * bintree :: Delet(node *n, int data)
{
    node *temp;
    if(n==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(data < n->data)
    {
        n->left = Delet(n->left, data);
    }
    else if(data > n->data)
    {
        n->right = Delet(n->right, data);
    }
    else
    {
        /* Now We can delete this node and replace with either minimum element
        in the right sub tree or maximum element in the left subtree */
        if(n->right && n->left)
        {
            /* Here we will replace with minimum element in the right sub tree */
            temp = FindMin(n->right);
            n -> data = temp->data;
            /* As we replaced it with some other node, we have to delete that node */
            n -> right = Delet(n->right,temp->data);
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
            temp = n;
            if(n->left == NULL)
                n = n->right;
            else if(n->right == NULL)
                n = n->left;
	    delete temp;
        }
    }
    return n;
}



node * bintree :: FindMin(node *n)
{
    if(n==NULL)
    {
        /* There is no element in the tree */
        return NULL;
    }
    if(n->left) /* Go to the left sub tree to find the min element */
        return FindMin(n->left);
    else
        return n;
}


void bintree :: mirror(node *root)
{
	node *t;
	if(root != NULL)
	{
	t=root->left;
	root->left=root->right;
	root->right=t;
	mirror(root->left);
	mirror(root->right);	
	}
	return;
}


void bintree :: BFS(node *temp)
{
queue <node*> q;
node *p1,*p2;
if(root == NULL)
{	cout<<"\nTree Is Not Created....";
	return;
}
q.push(temp);
cout<<" "<<temp->data;
	while(!q.empty())
	{
	p2=q.back();
		do
		{
		p1=q.front();		
		q.pop();
		if(p1->left!=NULL)
			{
			q.push(p1->left);
			cout<<" "<<(p1->left)->data;			
			}
		if(p1->right!=NULL)
			{
			q.push(p1->right);
			cout<<" "<<(p1->right)->data;
			}
		}while(p1!=p2);
	}
}

int main()
{
	int choice;
	char ans;
	bintree p,p1;
	do
	{	
		cout<<"\n1.Create \n2.Search \n3.Delete \n4.Display \n5.Levelwise Display \n6.Mirror \n7.Exit";
		cout<<"\nEnter Your Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
			do
			{
				p.create();
				cout<<"\nDo You Want to enter More Elements?(yn)";
				cin>>ans;
			}while(ans == 'y');
			break;
			case 2:p.find();
			break;
			case 3:p.delet();
			break;
			case 4:p.display();
			break;
			case 5:
			p.BFS(p.root);			
			break;
			case 6:
			p1=p;
			p1.mirror(p1.root);
			cout<<"Mirror is: ";
			p1.display();			
			break;
		}
	}while(choice != 7);
	return 0;
}

*************OUTPUT***************

[admin@localhost Downloads]$ g++ 5.cpp
[admin@localhost Downloads]$ ./a.out

1.Create 
2.Search 
3.Delete 
4.Display 
5.Levelwise Display 
6.Mirror 
7.Exit
Enter Your Choice:1

Enter the Element:5

Do You Want to enter More Elements?(yn)y

Enter the Element:3

Do You Want to enter More Elements?(yn)y

Enter the Element:7

Do You Want to enter More Elements?(yn)y

Enter the Element:1

Do You Want to enter More Elements?(yn)y

Enter the Element:9

Do You Want to enter More Elements?(yn)n

1.Create 
2.Search 
3.Delete 
4.Display 
5.Levelwise Display 
6.Mirror 
7.Exit
Enter Your Choice:2

Enter the Element Which You Want To Search:1

The 1 Element is Present
1.Create 
2.Search 
3.Delete 
4.Display 
5.Levelwise Display 
6.Mirror 
7.Exit
Enter Your Choice:3

Enter the Element You wish to Delete:9

1.Create 
2.Search 
3.Delete 
4.Display 
5.Levelwise Display 
6.Mirror 
7.Exit
Enter Your Choice:5
 5 3 7 1
1.Create 
2.Search 
3.Delete 
4.Display 
5.Levelwise Display 
6.Mirror 
7.Exit
Enter Your Choice:6
Mirror is: 
The Tree is: 7 5 3 1
1.Create 
2.Search 
3.Delete 
4.Display 
5.Levelwise Display 
6.Mirror 
7.Exit
Enter Your Choice:7

