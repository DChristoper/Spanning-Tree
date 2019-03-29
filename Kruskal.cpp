//Dean Christoper
//14116052
//Kruskal

#include <iostream>
#include <fstream>

#define inf 999
using namespace std;
    
    int parent[9];
    
int main () {
	int Size;
    int i=1;
    int j=1;
    int sisi=1;
	int x,y,u,v=1;
    int bobot_minimum=0; 
    int cari(int);
    int uni(int,int);
    int MIN;

	ifstream file;
	
	file.open("graf.txt");
 	
 	file>>Size;
 	
 	int cost[Size][Size];
 	
    	while (!file.eof()) 
	{
		for (i=1;i<=Size;i++)
		{
			for (j=1;j<=Size;j++)
			{
				file>>cost[i][j];
				
				if (cost[i][j]==-1)
				{
					cost[i][j]=inf;
				}
			} 
		}
 	
 	}
    	
    	
    	while(sisi < Size)
    	{
    		for(i=1,MIN=inf;i<=Size;i++)
    		{
    			for(j=1;j <= Size;j++)
    			{
    				if(cost[i][j] < MIN)
    				{
    					MIN=cost[i][j];
    					x=u=i;
    					y=v=j;
    				}
    			}
    		}
    		u=cari(u);
    		v=cari(v);
    		if(uni(u,v))
    		{
    			cout<<"("<<x<<","<<y<<") = "<<MIN<<endl;
    			sisi++;
    			bobot_minimum +=MIN;
    		}
    		cost[x][y]=cost[y][x]=inf;
    	}
    	cout<<"\nTotal bobot minimum spanning tree = "<<bobot_minimum;
    }
    int cari(int i)
    {
    	while(parent[i])
    	i=parent[i];
    	return i;
    }
    int uni(int i,int j)
    {
    	if(i!=j)
    	{
    		parent[j]=i;
    		return 1;
    	}
    	return 0;
    }
