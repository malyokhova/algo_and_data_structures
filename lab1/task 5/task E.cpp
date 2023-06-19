#include <iostream>

using namespace std;

int main()
{
    int n, Arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }

    int x, item = 0;
    cin >> x;
    int near = abs(x - Arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (abs(x - Arr[i]) < near)
        {
            near = abs(x - Arr[i]);
            item = i;
        }
    }

    cout << "\n" << Arr[item] << endl;

    return 0;
}
