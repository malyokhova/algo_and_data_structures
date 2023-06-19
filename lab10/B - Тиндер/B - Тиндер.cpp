#include <iostream>
#include <vector>
using namespace std;

void Init(int);
int Find(int);
void Union(int, int);

vector<int> parent;
vector<int> mySize;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    parent.resize(n);
    mySize.resize(n);
    for (int i = 0; i < n; i++)
    {
        Init(i);
    }

    int a, b;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        edges[i] = { a,b };
        Union(a, b);
    }

    char action;
    int start, end, index;
    for (int i = 0; i < q; i++)
    {
        cin >> action >> start >> end;
        start--;
        end--;
        switch (action)
        {
        case '?':
        {
            if (Find(start) == Find(end))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            break;
        }
        case '-':
        {
            index = -1;
            for (int j = 0; j < m; j++)
            {
                if ((edges[j].first == start && edges[j].second == end) || (edges[j].first == end && edges[j].second == start))
                {
                    index = j;
                    break;
                }
            }

            if (index != -1)
            {
                swap(edges[index], edges.back());
                edges.pop_back();
            }

            for (int k = 0; k < n; k++)
            {
                Init(k);
            }

            for (int k = 0; k < edges.size(); k++)
            {
                Union(edges[k].first, edges[k].second);
            }
            break;
        }
        default:
            break;
        }
    }
}

void Init(int v)
{
    parent[v] = v;
    mySize[v] = 1;
}

int Find(int v)
{
    if (v == parent[v])
    {
        return v;
    }

    return parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (mySize[a] < mySize[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        mySize[a] += mySize[b];
    }
}
