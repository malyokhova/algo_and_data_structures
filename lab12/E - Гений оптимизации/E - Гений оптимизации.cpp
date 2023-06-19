#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 200;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> flow(n, vector<int>(n));

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        cin >> flow[u][v];
    }

    int s = 0;
    int t = n - 1;

    int maxFlow = 0;
    vector<int> parent(n);

    while (true)
    {
        vector<int> c(n, maxSize);
        queue<int> q;
        q.push(s);
        while (!q.empty() && c[t] == maxSize)
        {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++)
            {
                if (flow[u][v] > 0 && c[v] == maxSize)
                {
                    c[v] = min(c[u], flow[u][v]);
                    parent[v] = u;
                    if (v == t)
                    {
                        break;
                    }
                    q.push(v);
                }
            }
        }

        if (c[t] == maxSize)
        {
            break;
        }

        maxFlow += c[t];
        int u = t;

        while (u != s)
        {
            int v = parent[u];
            flow[u][v] += c[t];
            flow[v][u] -= c[t];
            u = v;
        }
    }

    cout << maxFlow << endl;

    return 0;
}