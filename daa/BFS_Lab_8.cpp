#include <iostream>
#include <list>
using namespace std;

class Graph_BFS
{
    int Vertices;
    list<int> *adj;

public:
    Graph_BFS(int Vertices)
    {
        this->Vertices = Vertices;
        adj = new list<int>[Vertices];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int s)
    {

        bool *visited_node = new bool[Vertices];
        for (int i = 0; i < Vertices; i++)
            visited_node[i] = false;

        list<int> Q;

        visited_node[s] = true;
        Q.push_back(s);

        list<int>::iterator i;

        while (!Q.empty())
        {

            s = Q.front();
            cout << s << " ";
            Q.pop_front();

            for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited_node[*i])
                {
                    visited_node[*i] = true;
                    Q.push_back(*i);
                }
            }
        }
    }
};

int main()
{
    int Vertices, Edges, Edge_1, Edge_2, x;

    cout << "Enter the number of Vertices: ";
    cin >> Vertices;
    cout << "Enter the number of Edges: ";
    cin >> Edges;

    Graph_BFS G(Vertices);

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
        G.addEdge(Edge_1, Edge_2);
    }

    cout << "\nEnter the vertex to start BFS Traversalfrom : ";
    cin >> x;

    cout << "----------------BFS TRAVERSAL OF ABOVE GRAPH--------------";
    G.BFS(x);

    cout << endl;
    return 0;
}
