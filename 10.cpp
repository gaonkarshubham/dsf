#include <iostream>
#include <string.h>
#define MAX 10
using namespace std;
class prims
	{
		public:
		int cost[10][10],vertex,edge;
		void creatgraph();
		void primsfun(int);
	};
void prims::creatgraph()
	{
		int v1,v2,i,j,wt;
		cout<<"\n Enter The Maximum Number of Country: ";
		cin>>vertex;
		cout<<"\n Enter the Number of Phone Line: ";
		cin>>edge;
		for(i=1;i<=vertex;i++)
		for(j=1;j<=vertex;j++)
		cost[i][j]=0;
		for(i=1;i<=edge;i++)
			{
				cout<<"\n\t Enter the Phone Line And Their Cost(v1,v2,wt): ";
				cin>>v1>>v2>>wt;
				cost[v1][v2]=cost [v2][v1]=wt;
			}
	}
void prims::primsfun(int start)
	{
		int p,temp,min,visited[10],sum=0,k,m,j,i,n;
		for(i=1;i<=vertex;i++)
			{
				visited[i]=0;
			}
		visited[start]=1;
		for(k=1;k<=vertex-1;k++)
			{
				temp=999;
				for (i=1;i<=vertex;i++)
					{
						if (visited[i]==1)
							{
								min=999;		
								for(j=1;j<=vertex;j++)
									{			
										if(cost[i][j]!=0)
											{
												if (cost[i][j]<min && visited [j]==0)
													{
														min=cost[i][j];
														p=j;
													}
											}
									}
								if(min<temp)
									{
										temp=min;
										m=i;
										n=p;
									}
							}
					}	
				sum=sum+cost[m][n];
				cout<<"\n\t\t Selected Phone Line Of The Country: "<<"\t"<<m<<"\t"<<n<<"\t"<<cost[m][n];
				visited[m]=1;
				visited[n]=1;
			}
		cout<<"\n\t\t Business House Connected All Its Office with a Minimal Total Cost: "<<sum;
	}
int main()
	{
		prims s1;
		int start;
		int ch;
		do
			{
				cout<<"\n 1.Readgraph and Creategraph \n 2.Prims Algorithm \n 3.Exit \n";
				cout<<"\n Enter Your Choice::";
				cin>>ch;
				switch(ch)
					{
						case 1:   
							s1.creatgraph();
							break;
						case 2:
							cout<<"\n\t\t Enter the Business House No: ";
							cin>>start;
							s1.primsfun(start);
							break;
						case 3:
							cout<<"\n\t\t Thanks for Execution";
							break;
						default:
							cout<<"\n Enter Correct Choice: ";
					}
			}	
		while(ch!=3);
		return 0;
	}
