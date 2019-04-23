#include <bits/stdc++.h> 
using namespace std; 
#define V 5 

class MST
{
    int parent[V]; 
    int cost[V][V];
    public:
    
    int find(int i) 
{ 
	while (parent[i] != i) 
		i = parent[i]; 
	return i; 
} 

void union1(int i, int j) 
{ 
	int a = find(i); 
	int b = find(j); 
	parent[a] = b; 
} 

void kruskalMST(); 
    
};
void MST :: kruskalMST() 
{ 
    cout<<"\n Enter Cost Matrix: ";  
    for(int a=0;a<5;a++)
    for(int b=0;b<5;b++)
        cin>>cost[a][b];
	  int mincost = 0;

	for (int i = 0; i < V; i++) 
		parent[i] = i; 
	int edge_count = 0; 
	while (edge_count < V - 1) { 
		int min = INT_MAX, a = -1, b = -1; 
		for (int i = 0; i < V; i++) { 
			for (int j = 0; j < V; j++) { 
				if (find(i) != find(j) && cost[i][j] < min) { 
					min = cost[i][j]; 
					a = i; 
					b = j; 
				} 
			} 
		} 

		union1(a, b); 
		printf("Edge %d:(%d, %d) cost:%d \n", 
			edge_count++, a, b, min); 
		mincost += min; 
	} 
	printf("\n Minimum cost= %d \n", mincost); 
} 

int main() 
{ 
	MST t;
	t.kruskalMST(); 
	return 0; 
} 
