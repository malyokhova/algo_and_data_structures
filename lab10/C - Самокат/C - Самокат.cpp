#include <iostream>
#include <queue>
using namespace std;

void DFS1(vector<int> [], int*, int, int*);
void Visited(vector<int> [], bool*, int*, int, int, int*);
void DFS2(vector<int> [], int*, int, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int maxSize = 100;
    vector<int> G[maxSize];
    vector<int> H[maxSize];

    int n, m, q;
    cin >> n >> m >> q;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        H[b].push_back(a);
    }
    
    int* order = new int[n];
    int iOrd = 0;
    int* components = new int[n] {0};
    
    DFS1(G, order, n, &iOrd);

    int componentNum = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (components[order[i]] == 0)
        {
            DFS2(H, components, n, order[i], componentNum);
            componentNum++;
        }
    }

    int start, end;
    for (int i = 0; i < q; i++)
    {
        cin >> start >> end;
        start--;
        end--;
        if (components[start] == components[end])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

void DFS1(vector<int> adjacency[], int* order, int n, int* iOrd)
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

void Visited(vector<int> adjacency[], bool* visited, int* order, int n, int v, int* iOrd)
{
    visited[v] = true;
    for (int i = 0; i < adjacency[v].size(); i++)
    {
        if (!visited[adjacency[v][i]])
        {
            Visited(adjacency, visited, order, n, adjacency[v][i], iOrd);
        }
    }
    order[*iOrd] = v;
    (*iOrd)++;
}

void DFS2(vector<int> adjacency[], int* components, int n, int v, int component)
{
    components[v] = component;
    for (int i = 0; i < adjacency[v].size(); i++)
    {
        if (components[adjacency[v][i]] == 0)
        {
            DFS2(adjacency, components, n, adjacency[v][i], component);
        }
    }
}