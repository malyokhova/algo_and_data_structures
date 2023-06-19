#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
vector<vector<bool>> adjacency;
vector<int> match;
vector<bool> visited;

bool DFS(int u)
{
    for (int v : adjacency[u])
    {
        if (!visited[v])
        {
            visited[v] = true;

            if (match[v] == -1 || DFS(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }

    return false;
}

int MaxMatching()
{
    int count = 0;

    for (int u = 0; u < n * m; u++)
    {
        if(DFS(u))
        count ++;
    }

    return count;
}

int main()
{
    cin >> n >> m >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adjacency[x * m + y].clear();
    }

    for (int i = 0; i < n * m; i++) {
        if (i % m != m - 1 && !adjacency[i].empty() && !adjacency[i + 1].empty())
        {
            adjacency[i].push_back(i + 1);
            adjacency[i + 1].push_back(i);
        }

        if (i + m < n * m && !adjacency[i].empty() && !adjacency[i + m].empty())
        {
            adjacency[i].push_back(i + m);
            adjacency[i + m].push_back(i);
        }
    }

    cout << MaxMatching() << endl;

    return 0;
}