#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int size;
	list<int> *AD;

public:
	Graph(int Vertices)
	{
		this->size = Vertices;
		AD = new list<int>[Vertices];
	}

	void EDGE(int v, int w)
	{
		AD[v].push_back(w);
	}

	int cycle()
	{
		int *Visited_Node = new int[size];
		int *s_g = new int[size];

		for (int i = 0; i < size; i++)
		{
			Visited_Node[i] = 0;
			s_g[i] = 0;
		}

		for (int i = 0; i < size; i++)
			if (Check_Cycle_In_Graph(i, Visited_Node, s_g))
				return 1;

		return 0;
	}

	int Check_Cycle_In_Graph(int v, int Visited_Node[], int *s_g)
	{
		if (Visited_Node[v] == 0)
		{
			Visited_Node[v] = 1;
			s_g[v] = 1;

			list<int>::iterator i;
			for (i = AD[v].begin(); i != AD[v].end(); ++i)
			{
				if (!Visited_Node[*i] && Check_Cycle_In_Graph(*i, Visited_Node, s_g))
					return 1;
				else if (s_g[*i])
					return 1;
			}
		}

		s_g[v] = 0;
		return 0;
	}
};

int main()
{
	int Vertices, Edges, Edge_1, Edge_2, x;

	cout << "Enter the number of Vertices: ";
	cin >> Vertices;
	cout << "Enter the number of Edges: ";
	cin >> Edges;

	Graph G(Vertices);

	cout << "The vertices are: ";
	for (int i = 0; i < Vertices; i++)
	{
		cout << i << " ";
	}
	cout << "\n";
	for (int i = 0; i < Edges; i++)
	{
		cout << "Enter edge " << i + 1 << ": ";
		cin >> Edge_1 >> Edge_2;
		G.EDGE(Edge_1, Edge_2);
	}

	if (G.cycle())
		cout << "\033[1;32m-------------The Graph is cyclic------------\n";
	else
		cout << "\033[1;32m-------------The Graph is not cyclic-------------\n";

	cout << "\n";
	return 0;
}