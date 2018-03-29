#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<algorithm>
using namespace std;

int vertices;
std::vector<std::vector<int>> adjacencyMatrix;
std::vector<int> visited;
	
queue<int> q;

void BFS(int start_vertex)
{
	visited[start_vertex]=1;
	for(int i=0;i<vertices;i++)
	{
		if((i!=start_vertex) && (adjacencyMatrix[start_vertex][i]==1) & (visited[i]==0))
		{
			q.push(i);
			visited[i]=1;
		}
	}
	cout<<start_vertex<<" ";
	while(q.size()>0)
	{
		start_vertex=q.front();
		q.pop();
		for(int i=0;i<vertices;i++)
		{
			if((i!=start_vertex) && (adjacencyMatrix[start_vertex][i]==1) & (visited[i]==0))
			{
				q.push(i);
				visited[i]=1;
			}
		}
		cout<<start_vertex<<" ";	
	}
}

int main(int argc, char *argv[])
{
	string line;
	ifstream myfile(argv[1]);
	std::vector<string> edgeLists;
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			edgeLists.push_back(line);
		}
	}

	vertices=stoi(edgeLists[0]);
	int edges=stoi(edgeLists[1]);
	for(int i=0;i<vertices;i++)
	{
		adjacencyMatrix.push_back(std::vector<int>());
		for(int j=0;j<vertices;j++)
		{
			adjacencyMatrix[i].push_back(0);
		}
	}
	int sd[2],r=0;
	string token;
	for(int i=2;i<edgeLists.size();i++)
	{
		istringstream iss(edgeLists[i]);
		while(getline(iss,token,' '))
		{
			sd[r]=stoi(token);
			r++;
		}
		r=0;
		adjacencyMatrix[sd[0]][sd[1]]=1;
		adjacencyMatrix[sd[1]][sd[0]]=1;
	}

	cout<<"Given Adjacency Matrix is \n";
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<adjacencyMatrix[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i=0;i<vertices;i++)
		visited.push_back(0);


	int start_vertex;
	cout<<"\nEnter the start vertex for DFS\n";
	cin>>start_vertex;
	int comp=0,ind=0;	
	BFS(start_vertex);
	
	return 0;
}