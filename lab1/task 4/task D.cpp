#include <iostream>

using namespace std;

int main()
{
    int n, Arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }

    int k = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (Arr[i] > Arr[i - 1] && Arr[i] > Arr[i + 1])
        {
            k++;
        }
    }

    cout << "\n" << k << endl;
   
    return 0;
}
