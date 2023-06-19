#include <iostream>
#include <queue>
using namespace std;

void DFS1(bool**, int*, int, int*);
void Visited(bool**, bool*, int*, int, int, int*);
void DFS2(bool**, int*, int, int, int);
//void Floyd(bool**, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    bool** G = new bool* [n];
    for (int i = 0; i < n; i++)
    {
        G[i] = new bool[n] {false};
    }

    bool** H = new bool* [n];
    for (int i = 0; i < n; i++)
    {
        H[i] = new bool[n] {false};
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a - 1][b - 1] = true;
        H[b - 1][a - 1] = true; // inverted graph
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

    //Floyd(adjacency, n);
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
        /*if (adjacency[start][end] && adjacency[end][start])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        i += 1;*/
    }
}

void DFS1(bool** adjacency, int* order, int n, int* iOrd)
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

void Visited(bool** adjacency, bool* visited, int* order, int n, int v, int* iOrd)
{
    visited[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (adjacency[v][i] && !visited[i])
        {
            Visited(adjacency, visited, order, n, i, iOrd);
        }
    }
    order[*iOrd] = v;
    (*iOrd)++;
}

void DFS2(bool** adjacency, int* components, int n, int v, int component)
{
    components[v] = component;
    for (int i = 0; i < n; i++)
    {
        if (adjacency[v][i] && components[i] == 0)
        {
            DFS2(adjacency, components, n, i, component);
        }
    }
}

// Floyd

//void Floyd(bool** adjacency, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        for (int s = 0; s < n; s++)
//        {
//            for (int e = 0; e < n; e++)
//            {
//                if (adjacency[s][i] && adjacency[i][e])
//                {
//                    adjacency[s][e] = true;
//                }
//            }
//        }
//    }
//}