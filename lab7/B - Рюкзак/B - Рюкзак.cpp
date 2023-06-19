#include <iostream>
using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;
    
    int** bag = new int* [n + 1];
    for (int i = 0; i <= n; i++)
    {
        bag[i] = new int[s + 1] {0};
    }

    int* gold = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> gold[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (gold[i - 1] <= j)
            {
                int someGolds = bag[i - 1][j - gold[i - 1]] + gold[i - 1];
                if (bag[i - 1][j] > someGolds)
                {
                    bag[i][j] = bag[i - 1][j];
                }
                else
                {
                    bag[i][j] = someGolds;
                }
            }
            else
            {
                bag[i][j] = bag[i - 1][j];
            }
        }
    }

    cout << bag[n][s];
}
