//cs20b1085 gugulothu ravindar

//  Given the Routing Table  with "n" nodes,

//   Work on "Distance Vector Routing Algorithm", where

// Inputs: No of nodes, edges, and weights (distance)
// Output: the calculated value of distance (minimum).



#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int Cost = 100;
vector<pair<int, int>> c[Cost]; 

int parent[Cost] = {-1}; 
void bellman(int n, int m, int s)
{
	memset(parent, -1, sizeof(parent));
	vector<int> distance(n + 1, 1e9+6);
	distance[s] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (auto e : c[j])
			{
				int y = e.first;
				int z = e.second;
				if (distance[j] + z < distance[y])
				{
					distance[y] = distance[j] + z;
					parent[y] = j;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		vector<int> path;
		int current = i;
		while (current != -1)
		{
			path.push_back(current);
			current = parent[current];
		}
		reverse(path.begin(), path.end());
		if(path.size() == 1)
			cout << i << "\t\t" << distance[i] << "\t\t" << path[0] << endl;
		else
			cout << i << "\t\t" << distance[i] << "\t\t" << path[1] << endl;
	}
}
int main()
{
	int nodes, edges;
	cout<<"enter the total no of nodes and edges: "<<endl;
	cin >> nodes >> edges;
	cout<<"enter the nodes and edges: "<<endl;

	for (int i = 0; i < edges; i++)
	{
		int x, y, z;
		cin >> x >> y >> z; 
		c[x].push_back({y, z});
		c[y].push_back({x, z});
	}
	cout << " Bellman-Ford algorithm " << endl;
	
	for (int i = 1; i <= nodes; i++)
	{
		cout << "Routing table for " << i << endl;
		cout << "Desination\tDistance\tNext Hop" << endl;
		
		bellman(nodes, edges, i);
		
	}

	return 0;
}