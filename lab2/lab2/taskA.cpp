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

    int num, pos;
    cin >> num >> pos;
    pos--;

    for (int i = n; i > pos; i--)
    {
        Arr[i] = Arr[i - 1];
    }
    Arr[pos] = num;

    cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}
