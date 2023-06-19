#include <iostream>
using namespace std;

char** InputArray(int, int, char**);
void OutputArray(int, int, char**);
char** DigitalSearch(int, int, int, char**);

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    char** arr = new char*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
    }

    arr = InputArray(n, m, arr);
    arr = DigitalSearch(n, m, k, arr);
    OutputArray(n, m, arr);

    return 0;
}

char** InputArray(int n, int m, char** Arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Arr[i][j];
        }
    }
    return Arr;
}

void OutputArray(int n, int m, char** Arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << Arr[i][j];
        }
        cout << "\n";
    }
}

char** DigitalSearch(int n, int m, int k, char** Arr)
{
    for (int j = m - 1; j >= m - k; j--)
    {
        for (int i = 1; i < n; i++)
        {
            for (int t = i; t > 0; t--)
            {
                if (Arr[t - 1][j] > Arr[t][j])
                {
                    swap(Arr[t - 1], Arr[t]);
                }
                else
                {
                    break;
                }
            }
        }
    }

    return Arr;
}

