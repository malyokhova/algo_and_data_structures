#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> adjacency(n);
    int fromVertex, toVertex, weight;
    int balance = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> fromVertex >> toVertex >> weight;
        fromVertex--;
        toVertex--;
        balance += weight;
    }

    if (balance < 0)
    {
        cout << "1";
    }
    else
    {
        cout << "-1";
    }
}