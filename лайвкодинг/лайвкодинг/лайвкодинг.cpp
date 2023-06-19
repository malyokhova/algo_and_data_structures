#include <iostream>
#include <queue>
using namespace std;

void DFS1(vector<Edges>[], int*, int, int*);
void Visited(vector<Edges>[], bool*, int*, int, int, int*);
void DFS2(vector<Edges>[], int*, int, int, int);

struct Edges
{
    int fromVertex;
    int toVertex;
    int weight;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<Edges> adjacency(m);
    int fromVertex;
    for (int i = 0; i < m; i++)
    {
        cin >> adjacency[i].fromVertex >> adjacency[i].toVertex >> adjacency[i].weight;
        adjacency[i].fromVertex--;
        adjacency[i].toVertex--;
    }

    int* order = new int[n];
    int iOrd = 0;
    int* components = new int[n] {0};
    DFS1(adjacency, order, n, &iOrd);

    int componentNum = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (components[order[i]] == 0)
        {
            DFS2(adjacency, components, n, order[i], componentNum);
            componentNum++;
        }
    }
}

void DFS1(vector<Edges> adjacency[], int* order, int n, int* iOrd)
{
    bool* visited = new bool[n] { false };

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            Visited(adjacency, visited, order, n, i, iOrd);
        }
    }
    delete[] visited;
}

void Visited(vector<Edges> adjacency[], bool* visited, int* order, int n, int v, int* iOrd)
{
    visited[v] = true;
    if (!visited[v])
    {
        Visited(adjacency, visited, order, n, adjacency[v][i], iOrd);
    }
    order[*iOrd] = v;
    (*iOrd)++;
}

void DFS2(vector<int> adjacency[], int* components, int n, int v, int component)
{
    int balance;
    components[v] = component;
    for (int i = 0; i < adjacency[v].size(); i++)
    {
        if (components[adjacency[v][i]] == 0)
        {
            DFS2(adjacency, components, n, adjacency[v][i], component);
        }
    }
}