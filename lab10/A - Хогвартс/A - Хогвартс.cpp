#include <iostream>
using namespace std;

struct Room
{
    int componentNum;
    char safe;
};

void DFS(Room*, bool**, int, int*);
void Visit(Room*, bool**, bool*, int, int, int);

int main()
{
    int n, m;
    cin >> n >> m;
    bool** adjacency = new bool* [n];
    for (int i = 0; i < n; i++)
    {
        adjacency[i] = new bool[n] {false};
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjacency[a - 1][b - 1] = 1;
        adjacency[b - 1][a - 1] = 1;
    }

    Room* rooms = new Room[n];
    for (int i = 0; i < n; i++)
    {
        cin >> rooms[i].safe;
    }

    int k;
    DFS(rooms, adjacency, n, &k);

    for (int i = 0; i < n; i++)
    {
        delete[] adjacency[i];
    }
    delete[] adjacency;

    bool* dangerous = new bool[k] {false};
    for (int i = 0; i < n; i++)
    {
        if (rooms[i].safe == '1')
        {
            dangerous[rooms[i].componentNum - 1] = true;
        }
    }

    cout << k << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << rooms[i].componentNum << " ";
    }
    cout << "\n";
    for (int i = 0; i < k; i++)
    {
        if (dangerous[i])
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }
}

void DFS(Room* rooms, bool** adjacency, int n, int* k)
{
    *k = 0;
    bool* vertex = new bool[n] { false };
    for (int i = 0; i < n; i++)
    {
        if (!vertex[i])
        {
            (*k)++;
            Visit(rooms, adjacency, vertex, n, i, *k);
        }
    }
    delete[] vertex;
}

void Visit(Room* rooms, bool** adjacency, bool* vertex, int n, int roomNum, int componentNum)
{
    vertex[roomNum] = true;
    rooms[roomNum].componentNum = componentNum;
    for (int i = 0; i < n; i++)
    {
        if (adjacency[roomNum][i] && !vertex[i])
        {
            Visit(rooms, adjacency, vertex, n, i, componentNum);
        }
    }
}