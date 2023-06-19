#include <iostream>

using namespace std;

int main()
{
    int n, Arr[35];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }

    int temp = Arr[n-1];
    for (int i = n - 1; i > 0; i--)
    {
        Arr[i] = Arr[i - 1];
    }
    Arr[0] = temp;

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
