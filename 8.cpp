/*-------------------------------------------------------------------
			ASSIGNMENT NO. 8 
TITLE  :- Represent a given graph using adjacency matrix/adjacency list and 
	find the shortest path using Dijkstra's algorithm.
--------------------------------------------------------------------*/
#include<iostream>
#define MAX 10
#define INFINITY 9999
using namespace std;
class dj
{
int cost[MAX][MAX],distance[MAX],pred[MAX];
public:
	void dijkstra(int G[MAX][MAX],int n, int startnode);
};

void dj :: dijkstra(int G[MAX][MAX],int n, int startnode)
{
	int visited[MAX],count,mindistance,nextnode,i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;visited[i]=0;
	}
	distance[startnode]=0;visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=INFINITY ;
		for(i=0;i<n;i++)
			if(distance[i] <mindistance&& !visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i<n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
		count++;
	}
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			cout<<"\n DISTANCE OF "<< i << " = " << distance[i];
			cout<<"\nPATH = "<<i;
			j=i;
			do
			{
				j=pred[j];
				cout<<"<- "<<j;
			}while(j!=startnode);
		}
}

//Main Function
int main()
{
	dj pk;
	int G[MAX][MAX],i,j,n,noofedges,u,v,w;
	cout<<"\nENTER NO OF VERTICES: ";
	cin>>n;
	cout<<"\nENTER NO OF EDGES: ";
	cin>>noofedges;
	cout<<"\nENTER EDGES (u,v,weight): ";
	for(i=0;i<noofedges;i++)
	{
		cin>>u>>v>>w;
		G[u][v]=G[v][u]=w;
	}
	cout<<"\nENTER THE STARTING NODE: ";
	cin>>u;
	pk.dijkstra(G,n,u);
}

*************OUTPUT***************
OUTPUT:
ENTER NO OF VERTICES: 4
ENTER NO OF EDGES: 5
ENTER EDGES (u,v,weight): 0 1 2
1 2 1
2 3 2
3 0 5
0 2 3
ENTER THE STARTING NODE: 1
DISTANCE OF 0 = 2
PATH = 0 <- 1
DISTANCE OF 2 = 1
PATH = 2 <- 1
DISTANCE OF 3 = 3
PATH = 3 <- 2 <- 1 

