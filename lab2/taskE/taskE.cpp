#include <iostream>
using namespace std;

void InputArray(int**, int, int);
void OutputArray(int**, int, int);
void Sort(int**, int, int);
void Swap(int*, int*, int);

int main()
{
    int n, m = 2;
    cin >> n;
    int** Arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        Arr[i] = new int[m];
    }

    InputArray(Arr, n, m);
    Sort(Arr, n, m);
    OutputArray(Arr, n, m);

    return 0;
}

void InputArray(int** Array, int sizei, int sizej)
{
    for (int i = 0; i < sizei; i++)
    {
        for (int j = 0; j < sizej; j++)
        {
            cin >> Array[i][j];
        }
    }
}

void OutputArray(int** Array, int sizei, int sizej)
{
    cout << endl;
    for (int i = 0; i < sizei; i++)
    {
        for (int j = 0; j < sizej; j++)
        {
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }
}

void Sort(int** Array, int sizei, int sizej)
{
    for (int i = 0; i < sizei; i++)
    {
        for (int j = sizei - 1; j > i; j--)
        {
            if (Array[j][sizej - 1] > Array[j - 1][sizej - 1])
            {
                Swap(Array[j], Array[j - 1], sizej);
            }
            else if (Array[j][sizej - 1] == Array[j - 1][sizej - 1])
            {
                if (Array[j][sizej - 2] < Array[j - 1][sizej - 2])
                {
                    Swap(Array[j], Array[j - 1], sizej);
                }
            }
        }
    }
}

void Swap(int* num1, int* num2, int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = num1[i];
        num1[i] = num2[i];
        num2[i] = temp;
    }
}