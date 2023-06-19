#include <iostream>
using namespace std;

void InputArray(int*, int);
void OutputArray(int*, int);
void Swap(int*, int*);

int main()
{
    int n, Arr[100];
    cin >> n;
    InputArray(Arr, n);

    bool output;
    for (int i = 1; i < n; i++)
    {
        output = false;
        for (int j = i; j > 0; j--)
        {
            if (Arr[j - 1] > Arr[j])
            {
                Swap(&Arr[j - 1], &Arr[j]);
                output = true; 
            }
            else 
            {
                break;                                
            }
        }
        if (output)
        {
            OutputArray(Arr, n);
        }
    }

    return 0;
}

void InputArray(int* Array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> Array[i];
    }
}

void OutputArray(int* Array, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Array[i] << " ";
    }
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
