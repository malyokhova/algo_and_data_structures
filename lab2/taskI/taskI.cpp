#include <iostream>
using namespace std;

void InputArray(int*, int);
void OutputArray(int*, int);
void Swap(int*, int*);
void QuickSort(int*, int, int);

int main()
{
    int n, Arr[100000];
    cin >> n;
    InputArray(Arr, n);
    QuickSort(Arr, 0, n - 1);
    OutputArray(Arr, n);

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

void QuickSort(int* Array, int l, int r)
{
    int middle = (l + r) / 2;
    int pivot = Array[middle];
    int i = l, j = r;
    while (i <= j)
    {
        while (Array[i] < pivot)
        {
            i++;
        }

        while (Array[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            Swap(&Array[i++], &Array[j--]);
        }
    }

    if (l < j)
    {
        QuickSort(Array, l, j);
    }

    if (r > i)
    {
        QuickSort(Array, i, r);
    }
}