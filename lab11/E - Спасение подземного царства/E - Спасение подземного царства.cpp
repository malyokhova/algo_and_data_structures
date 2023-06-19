#include <iostream>
using namespace std;

float* Deikstra(float** adjacency, int n, int start);

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;

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

    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        cin >> adjacency[a][b];
    }

    float* distance = new float[n];
    distance = Deikstra(adjacency, n, s);

    if (distance[t] == INFINITY)
    {
        cout << "-1\n";
    }
    else
    {
        cout << distance[t] << endl;
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