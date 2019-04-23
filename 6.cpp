#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAX 10
using namespace std;

struct node
{
    int vertex;
    int comments;
    char dob[MAX];

    struct node *next;
};

struct friends
{
    int nof;
    int comments;
    char dob[MAX];
};


class queue
{
    int f,r;
    int data[MAX];
    public:
    queue()
    {
        f=r=-1;
    }
    int empty()
    {
        if(f==-1)
            return 1;
        return 0;
    }
    void enq(int x)
    {
        if(empty())
            f=r=0;
        else
            r++;
        data[r]=x;
    }

    int deq()
    {
        int x=data[f];
        if(f==r)
            f=r=-1;
        else
            f++;
        return x;
    }
};



class facebook
{
    node *head[MAX];
    int visited[MAX];
    friends frnd[MAX];
    int n,e;

public:
    facebook()
    {
        int i;

        for(i=0;i<MAX;i++)
        {
            head[i]=NULL;
            visited[i]=0;
        }
    }

    void create()
    {
        int v1,v2,i;
        cout<<"\nenter no. of vertices: ";
        cin>>n;
        cout<<"\nEnter no. of edges: ";
        cin>>e;

        for(i=0;i<e;i++)
        {
            cout<<"\nEnter edge(v1,v2):";
            cin>>v1>>v2;
            insert_edge(v1,v2);
            insert_edge(v2,v1);
        }
    }

    void insert_edge(int v1,int v2)
    {
        node *p;
        p=new node;
        p->vertex=v2;
        p->next=NULL;

        if(head[v1]==NULL)
            head[v1]=p;
        else
        {
            node *temp=head[v1];
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=p;
        }

        if(!visited[v1])
        {
            cout<<"\nEnter No. of commnets of V"<<v1<<":";
            cin>>head[v1]->comments;
            cout<<"\nEnter DOB(dd-mm-yy) of V"<<v1<<":";
            cin>>head[v1]->dob;
        }
        visited[v1]=1;
    }


    void bfs()
    {
        queue q;
        int i,nof,v1;
        node *temp;
        for(i=0;i<n;i++)//init visited again
        {
            visited[i]=0;
        }

        cout<<"\nEnter starting vertex: ";
        cin>>v1;
        q.enq(v1);
        cout<<"\nNode\t\tNo.of Frends\tNo. of Comments\tDOB";
        cout<<"\n-------------------------------------------------";
        while(!q.empty())
        {
            i=q.deq();


            temp=head[i];
            nof=0;
            while(temp!=NULL)
            {
                if(!visited[temp->vertex])
                {
                    q.enq(temp->vertex);
                }
                temp=temp->next;
                nof++;
            }
            frnd[i].nof=nof;
            frnd[i].comments=head[i]->comments;
            strcpy(frnd[i].dob,head[i]->dob);

            if(!visited[i])
            {
                visited[i]=1;
                cout<<"\n"<<i<<"\t\t"<<frnd[i].nof<<"\t\t"<<frnd[i].comments<<"\t\t"<<frnd[i].dob;
            }
        }
        cout<<"\n-------------------------------------------------";
        int maxf,friend_node,maxc,minc,ch;
        do
        {
            cout<<"\n1.Max Friends\n2.Max Comments\n3.Min Comments\n4.Birthday in Current Month\nEnter ur Choice:";
            cin>>ch;
            switch(ch)
            {
                case 1:
                        maxf=frnd[0].nof;
                        friend_node=0;
                        for(i=0;i<n;i++)
                        {
                            if(frnd[i].nof>maxf)
                            {
                                friend_node=i;
                                maxf=frnd[i].nof;
                            }
                        }
                        cout<<"\nThe node "<<friend_node<<" Having Maximum Friends="<<maxf;
                        break;
                case 2:
                        maxc=frnd[0].comments;
                        for(i=0;i<n;i++)
                        {
                            if(frnd[i].comments>maxc)
                            {
                                friend_node=i;
                                maxc=frnd[i].comments;
                            }
                        }
                        cout<<"\nThe node "<<friend_node<<" Having Maximum Comments="<<maxc;
                        break;
                case 3:
                         minc=frnd[0].comments;
                         for(i=0;i<n;i++)
                         {
                             if(frnd[i].comments<minc)
                             {
                                 friend_node=i;
                                 minc=frnd[i].comments;
                             }
                         }
                         cout<<"\nThe node "<<friend_node<<" Having Minimum Comments="<<minc;
                         break;
                case 4://Birthaday in this month
                        char mon[3];
                        cout<<"\nEnter Month= ";
                        cin>>mon;
                        char month[MAX][MAX];
                        for(i=0;i<n;i++)
                        {
                            month[i][0]=frnd[i].dob[3];
                            month[i][1]=frnd[i].dob[4];
                            month[i][2]='\0';
                        }
                        for(i=0;i<n;i++)
                        {
                            if(strcmp(mon,month[i])==0)
                                cout<<"\nNode "<<i;
                        }
                        cout<<"\nhaving Birthdays in this month";
                        break;
            }

        }while(1);
    }
};

int main()
{
	facebook f;
	f.create();
	f.bfs();
	return 0;
}

/* Output:-

student@student-OptiPlex-390:~$ g++ ass6.cpp
student@student-OptiPlex-390:~$ ./a.out

enter no. of vertices: 5

Enter no. of edges: 5

Enter edge(v1,v2):0
1

Enter No. of commnets of V0:5

Enter DOB(dd-mm-yy) of V0:01-09-90

Enter No. of commnets of V1:7

Enter DOB(dd-mm-yy) of V1:05-07-91

Enter edge(v1,v2):0
2

Enter No. of commnets of V2:10

Enter DOB(dd-mm-yy) of V2:05-07-91

Enter edge(v1,v2):0
3

Enter No. of commnets of V3:3

Enter DOB(dd-mm-yy) of V3:15-09-83

Enter edge(v1,v2):3
4

Enter No. of commnets of V4:2

Enter DOB(dd-mm-yy) of V4:20-01-97

Enter edge(v1,v2):1
3

Enter starting vertex: 4

Node		No.of Frends	No. of Comments	DOB
-------------------------------------------------
4		1		2		20-01-97
3		3		3		15-09-83
0		3		5		01-09-90
1		2		7		05-07-91
2		1		10		05-07-91
-------------------------------------------------
1.Max Friends
2.Max Comments
3.Min Comments
4.Birthday in Current Month
Enter ur Choice:1

The node 0 Having Maximum Friends=3
1.Max Friends
2.Max Comments
3.Min Comments
4.Birthday in Current Month
Enter ur Choice:2

The node 2 Having Maximum Comments=10
1.Max Friends
2.Max Comments
3.Min Comments
4.Birthday in Current Month
Enter ur Choice:3

The node 4 Having Minimum Comments=2
1.Max Friends
2.Max Comments
3.Min Comments
4.Birthday in Current Month
Enter ur Choice:4

Enter Month= 09

Node 0
Node 3
having Birthdays in this month
1.Max Friends
2.Max Comments
3.Min Comments
4.Birthday in Current Month
Enter ur Choice:

*/

