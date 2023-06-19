#include <iostream>
using namespace std;

int Ford(int** edges, int n, int m);
void Relax(float* distance, int u, int v, int w);

int main()
{
    int grafsCount, maxLength;
    cin >> grafsCount >> maxLength;

    int n, m, start, end;
    for (int i = 0; i < grafsCount; i++)
    {
        cin >> n >> m;
        int** edges = new int* [m];
        for (int j = 0; j < m; j++)
        {
            edges[j] = new int[3];
            cin >> start >> end;
            start--;
            end--;
            edges[j][0] = start;
            edges[j][1] = end;
            cin >> edges[j][2];
        }

        if (Ford(edges, n, m) <= maxLength)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        for (int i = 0; i < m; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;
    }
}

int Ford(int** edges, int n, int m)
{
    float* distance = new float[n] {INFINITY};
    distance[0] = 0;
    int* parent = new int[n] {-1};
    int lastRelaxedVertex = -1;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Relax(distance, edges[j][0], edges[j][1], edges[j][2]);
            if (distance[edges[j][1]] > distance[edges[j][0]] + edges[j][2])
            {
                distance[edges[j][1]] = distance[edges[j][0]] + edges[j][2];
                parent[edges[j][1]] = edges[j][0];
                lastRelaxedVertex = edges[j][1];
            }
        }
    }

    bool cycle = false;
    for (int i = 0; i < m; i++)
    {
        if (distance[edges[i][0]] > distance[edges[i][1]] + edges[i][2])
        {
            cycle = true;
        }
    }

    if (!cycle)
    {
        return -1;
    }

    int count = 1;
    if (lastRelaxedVertex == -1)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            // cout << lastRelaxedVertex << endl; ///////////////////////////////////////////////
            lastRelaxedVertex = parent[lastRelaxedVertex];
        }
        int vertex = lastRelaxedVertex;
        while (vertex != lastRelaxedVertex)
        {
            vertex = parent[vertex];
            count++;
        }
    }

    return count;
}

void Relax(float* distance, int u, int v, int w)
{
    if (distance[v] > distance[u] + w)
    {
        distance[v] = distance[u] + w;
    }
}