#include <iostream>
using namespace std;

void InputArray(int*, int);
void OutputArray(int*, int);
void Swap(int*, int*);
void QuickSort(int*, int, int);
int Count(int*, int*, int, int);

int main()
{
    int n, m;
    cin >> n >> m;
    int size = n * m;
    int* rafts = new int[size];
    InputArray(rafts, size);

    int k;
    cin >> k;
    int* weight = new int[k];
    InputArray(weight, k);

    QuickSort(rafts, 0, size - 1);
    QuickSort(weight, 0, k - 1);

    cout << Count(rafts, weight, size, k);

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

int Count(int* rafts, int* weight, int sizeR, int sizeW)
{
    int count = 0;
    int i = 0, raftIndex = 0;

    while (i < sizeR && raftIndex < sizeW)
    {
        for (int j = raftIndex; j < sizeR; j++)
        {
            if (weight[i] <= rafts[j])
            {
                count++;
                raftIndex = ++j;
                break;
            }
        }
        i++;
    }

    return count;
}