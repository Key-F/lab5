//! \mainpage Программа, реализующая различные обходы деревьев \file <main.cpp>
#include <iostream>
using namespace std;


void Da(int **GR, int st, int n) //!<алгоритм Дейкстры
{
int  count, index, i, u, m=st+1;
bool *visited = new bool[n];
int *distance = new int[n];
for (i=0; i<n; i++)
{
 distance[i]=INT_MAX; visited[i]=false;
}
 distance[st]=0;
for (count=0; count<n-1; count++)
{
int min=INT_MAX;
for (i=0; i<n; i++)
if (!visited[i] && distance[i]<=min)
{
 min=distance[i]; index=i;
}
 u=index;
 visited[u]=true;
for (i=0; i<n; i++)
if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX &&
 distance[u]+GR[u][i]<distance[i])
 distance[i]=distance[u]+GR[u][i];
}
cout<<"Rast:\n";
for (i=0; i<n; i++) if (distance[i]!=INT_MAX)
cout<<m<<" > "<<i+1<<" = "<<distance[i]<<endl;
else cout<<m<<" > "<<i+1<<" = "<<"error"<<endl;
}
//! Функция main() − точка входа в программу.
void main()
{
	cout<<"KolUzlov: ";
    int n; 
    cin >> n;
	int **GR=new int*[n];
      for (int i=0;i<n;i++) GR[i]=new int [n];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			cout << "(" <<i<<", "<<j<<"): ";
		    cin >> GR[i][j];
		}

 Da(GR ,0, n);
system("pause>>void");
}