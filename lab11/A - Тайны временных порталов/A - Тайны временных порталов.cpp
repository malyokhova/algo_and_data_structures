#include <iostream>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    float** adjacency = new float*[n];
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
        cin >> a >> b >> w;
        a--;
        b--;
        adjacency[a][b] = w;
    }

    int q;
    cin >> q;
    float min;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        min = adjacency[a][b];
        for (int v = 0; v < n; v++)
        {
            if (abs(a - v) > k || abs(b - v) > k)
            {
                continue;
            }

            if (min > adjacency[a][v] + adjacency[v][b])
            {
                min = adjacency[a][v] + adjacency[v][b];
            }
        }

        if (min == INFINITY)
        {
            cout << "-1\n";
        }
        else
        {
            cout << min << "\n";
        }
    }
}
