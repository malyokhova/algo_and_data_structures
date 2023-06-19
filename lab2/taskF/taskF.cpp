#include <iostream>
using namespace std;

void InputArray(int*, int);
void OutputArray(int*, int);
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);


int main()
{
    int n, Arr[100];
    cin >> n;

    InputArray(Arr, n);
    MergeSort(Arr, 0, n);
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

void MergeSort(int* Array, int l, int r)
{
    if (l + 1 >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    MergeSort(Array, l, mid);
    MergeSort(Array, mid, r);
    Merge(Array, l, mid, r);
}

void Merge(int* Array, int l, int mid, int r)
{
    int i1 = 0;
    int i2 = 0;
    int* result = new int[r-l];
    while (l + i1 < mid && mid + i2 < r)
    {
        if (Array[l + i1] < Array[mid + i2])
        {
            result[i1 + i2] = Array[l + i1];
            i1++;
        }
        else
        {
            result[i1 + i2] = Array[mid + i2];
            i2++;
        }
    }

    while (l + i1 < mid)
    {
        result[i1 + i2] = Array[l + i1];
        i1++;
    }

    while (mid + i2 < r)
    {
        result[i1 + i2] = Array[mid + i2];
        i2++;
    }

    for (int i = 0; i < i1 + i2; i++)
    {
        Array[l + i] = result[i];
    }

    delete[] result;
}