//Dean Christoper
//14116052
//Prim


#include <iostream>
#include <fstream>

#define inf 999
using namespace std;

int main() {
	int Size, MIN;
 	int X, Y, U, V;
	int skip[100]={0};
	int bobot_minimum=0;
	int sisi=1;
	int i=1;
	int j=1;
	
	ifstream file;
 	
 	file.open("graf.txt");
 	
 	file>>Size;
 	
 	int matriks[Size][Size];
 	
	while (!file.eof()) 
	{
		for (i=1;i<=Size;i++)
		{
			for (j=1;j<=Size;j++)
			{
				file>>matriks[i][j];
				
				if (matriks[i][j]==-1)
				{
					matriks[i][j]=inf;
				}
			} 
		}
 	
 	}
 	file.close();
	
	skip[1]=1;
 
	while(sisi < Size)
	{
 
		for(i=1,MIN=inf;i<=Size;i++)
 
		for(j=1;j<=Size;j++)
 
		if(matriks[i][j]< MIN)
 
		if(skip[i]!=0)
 
		{
 
			MIN=matriks[i][j];
 
			X=U=i;
 
			Y=V=j;
 
		}
 
		if(skip[U]==0 || skip[V]==0)
 
		{
 			sisi++;
 			cout<<"("<<X<<","<<Y<<") = "<<MIN<<endl; 				
			bobot_minimum+=MIN;
			skip[Y]=1;
 
		}
 
		matriks[X][Y]=matriks[Y][X]=inf;
 
	}
 
	cout<<"\nTotal bobot minimum spanning tree = "<<bobot_minimum;
 
	return 0;
 
}
