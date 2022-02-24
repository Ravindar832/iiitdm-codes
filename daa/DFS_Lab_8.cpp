#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class GRAPH_DFS
{
public:
    map<int, bool> Visited_Node;
    map<int, list<int>> adj;

    void EDGE(int v, int w)
    {
        adj[v].push_back(w);
    }

    void DFS(int v)
    {
        Visited_Node[v] = true;
        cout << v << " ";

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!Visited_Node[*i])
                DFS(*i);
    }
};

int main()
{
    int Vertices, Edges, Edge_1, Edge_2, x;

    cout << "Enter the number of Vertices: ";
    cin >> Vertices;
    cout << "Enter the number of Edges: ";
    cin >> Edges;

    GRAPH_DFS G;

    cout << "The vertices are: ";
    for (int i = 0; i < Vertices; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < Edges; i++)
    {
        cout << "Enter edge " << i + 1 << ": ";
        cin >> Edge_1 >> Edge_2;
        G.EDGE(Edge_1, Edge_2);
    }

    cout << "\nEnter the vertex to start DFS Traversal from : ";
    cin >> x;

    cout << "------------DFS TRAVERSAL OF GRAPH------------\n";
    G.DFS(x);

    cout << endl;
    return 0;
}
