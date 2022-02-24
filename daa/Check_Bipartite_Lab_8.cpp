// TEST FOR BIPARTITEDNESS
#include <iostream>
#include <vector>
using namespace std;

void EDGE(vector<int> Adjacent[], int u, int v)
{
	Adjacent[u].push_back(v);
	Adjacent[v].push_back(u);
}

int Check_Bipartite(vector<int> Adjacent[], int v, vector<int> &Visted_Node, vector<int> &C_K)
{
	for (int u : Adjacent[v])
	{
		if (Visted_Node[u] == 0)
		{
			Visted_Node[u] = 1;
			C_K[u] = !C_K[v];
			if (!Check_Bipartite(Adjacent, u, Visted_Node, C_K))
				return 0;
		}
		else if (C_K[u] == C_K[v])
			return 0;
	}
	return 1;
}

int main()
{
	int Vertices, Edges, Edge_1, Edge_2, x;

	cout << "Enter the number of Vertices: ";
	cin >> Vertices;
	cout << "Enter the number of Edges: ";
	cin >> Edges;

	cout << "The vertices are: ";
	for (int i = 0; i < Vertices; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int> Adjacent[Vertices + 1];

	vector<int> Visted_Node(Vertices + 1);
	vector<int> C_K(Vertices + 1);
	for (int i = 0; i < Edges; i++)
	{
		cout << "Enter edge " << i + 1 << ": ";
		cin >> Edge_1 >> Edge_2;
		EDGE(Adjacent, Edge_1, Edge_2);
	}

	Visted_Node[1] = 1;
	C_K[1] = 0;

	if (Check_Bipartite(Adjacent, 1, Visted_Node, C_K))
	{
		cout << "\033[1;32m------------Graph is Bipartite--------------\n";
	}
	else
	{
		cout << "\033[1;32m------------Graph is not Bipartite--------------\n";
	}
	cout << endl;
	return 0;
}
