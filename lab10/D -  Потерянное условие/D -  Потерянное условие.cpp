#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> TopSort(vector<int> [], int);
void DFS(vector<int> [], bool*, int, int, stack<int>*);
void GetResult(stack<int>, int*, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int>* adjacency = new vector<int>[n];

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adjacency[a].push_back(b);
    }

    int* result = new int[n];
    GetResult(TopSort(adjacency, n), result, n);    

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}

stack<int> TopSort(vector<int> adjacency[], int n)
{
    stack<int> topSort;
    bool* visited = new bool[n] { false };
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(adjacency, visited, n, i, &topSort);
        }
    }

    delete[] visited;
    return topSort;
}

void DFS(vector<int> adjacency[], bool* visited, int n, int v, stack<int>* topSort)
{
    visited[v] = true;
    for (int i = 0; i < adjacency[v].size(); i++)
    {
        if (!visited[adjacency[v][i]])
        {
            DFS(adjacency, visited, n, adjacency[v][i], topSort);
        }
    }
    (*topSort).push(v);
}

void GetResult(stack<int> topSort, int* result, int n)
{
    int v, count = 1;
    for (int i = 0; i < n; i++)
    {
        v = topSort.top();
        topSort.pop();
        result[v] = count;
        count++;
    }
}