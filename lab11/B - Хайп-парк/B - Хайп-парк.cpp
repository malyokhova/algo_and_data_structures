#include <iostream>
using namespace std;

void Floyd(float**, int);

int main()
{
    int n, m;
    cin >> n >> m;

    float** adjacency = new float* [n];
    for (int i = 0; i < n; i++)
    {
        adjacency[i] = new float[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjacency[i][j] = INFINITY;
        }
    }

    int s, e, l;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> l;
        s--;
        e--;
        adjacency[s][e] = adjacency[e][s] = l;
    }

    Floyd(adjacency, n);

    float distance = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (adjacency[i][j] != INFINITY && distance < adjacency[i][j])
            {
                distance = adjacency[i][j];
            }
        }
    }

    if (distance == 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << distance << endl;
    }
}

void Floyd(float** adjacency, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (adjacency[u][v] > adjacency[u][i] + adjacency[i][v])
                {
                    adjacency[u][v] = adjacency[v][u] = adjacency[u][i] + adjacency[i][v];
                }
            }
        }
    }
}
