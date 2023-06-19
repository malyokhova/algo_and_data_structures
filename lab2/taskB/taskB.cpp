#include <iostream>
using namespace std;

void Swap(int*, int*);

int main()
{
    int n, Arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (Arr[j - 1] > Arr[j])
            {
                Swap(&Arr[j - 1], &Arr[j]);
            }
            else
            {
                break;
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
