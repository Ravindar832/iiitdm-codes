
#include <bits/stdc++.h>

using namespace std;

#define no 100
#define int_max 9999999

void dijkstraFunc(int G[no][no], int n, int startnode)
{
    int cst[no][no], dist[no], pred[no];
    int visited[no], cnt, mindistance, nn, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cst[i][j] = int_max;
            }
            else
            {
                cst[i][j] = G[i][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        dist[i] = cst[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    dist[startnode] = 0;
    visited[startnode] = 1;
    cnt = 1;
    while (cnt < n - 1)
    {
        mindistance = int_max;
        for (i = 0; i < n; i++)
        {
            if (dist[i] < mindistance && !visited[i])
            {
                mindistance = dist[i];
                nn = i;
            }
        }
        visited[nn] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cst[nn][i] < dist[i])
                {
                    dist[i] = mindistance + cst[nn][i];
                    pred[i] = nn;
                }
            }
        }
        cnt++;
    }
    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            cout << "Distance of node " << i + 1 << " = " << dist[i] << endl;
            cout << " Path = " << i + 1;
            j = i;
            do
            {
                j = pred[j];
                cout << "<-" << j + 1;
            } while (j != startnode);
            cout << endl;
        }
}

int main()
{
    int vertices, edges, u = 0;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    int ew[edges][3], a[no][no];

    cout << "\nEnter edges and their weigths: \n";
    for (int i = 0; i < edges; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> ew[i][j];
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i == j)
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = int_max;
            }
        }
    }

    for (int i = 0; i < edges; i++)
    {
        a[ew[i][1] - 1][ew[i][0] - 1] = ew[i][2];
        a[ew[i][0] - 1][ew[i][1] - 1] = ew[i][2];
    }

    dijkstraFunc(a, vertices, u);

    return 0;
}