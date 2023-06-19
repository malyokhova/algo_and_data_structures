#include <iostream>
using namespace std;

float* Deikstra(float** adjacency, int n, int start);

int main()
{
    int n, m, q, start;
    cin >> n >> m >> q >> start;
    q--;
    start--;

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

    int s, e, w;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        s--;
        e--;
        adjacency[s][e] = adjacency[e][s] = w;
    }

    float* distance = new float[n];
    distance = Deikstra(adjacency, n, start);

    int end;
    for (int i = 0; i < q; i++)
    {
        cin >> end;
        end--;
        if (distance[end] == INFINITY)
        {
            cout << "-1\n";
        }
        else
        {
            cout << distance[end] << endl;
        }
    }
}

float* Deikstra(float** adjacency, int n, int start)
{
    bool* visited = new bool[n];
    float* distance = new float[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INFINITY;
    }

    distance[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int min = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (min == -1 || distance[j] < distance[min]))
            {
                min = j;
            }
        }

        if (distance[min] == INFINITY)
        {
            break;
        }

        visited[min] = true;
        for (int j = 0; j < n; j++)
        {
            if (adjacency[min][j] != INFINITY && distance[min] + adjacency[min][j] < distance[j])
            {
                distance[j] = distance[min] + adjacency[min][j];
            }
        }
    }

    return distance;
}