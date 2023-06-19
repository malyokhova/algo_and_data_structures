#include <iostream>
using namespace std;

string IsPyramid(int, int[]);

int main()
{
    int n;
    cin >> n;

    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << IsPyramid(n, arr) << "\n";
}

string IsPyramid(int n, int Arr[])
{
    bool isPyramid;
    for (int i = 0; i < (n - 1) / 2; i++)
    {
        if (Arr[i] <= Arr[2 * i + 1] && Arr[i] <= Arr[2 * i + 2]);
        else
        {
            isPyramid = false;
            return "NO";
        }
    }

    return "YES";
}