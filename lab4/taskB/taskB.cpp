#include <iostream>
using namespace std;

void HeapSort(int, int*);
void SiftDown(int, int, int*);
void SiftUp(int, int*);
void BuildHeap(int, int*);
void OutputArray(int, int*);
void DrawHeap(int*, int);


int main()
{
    int n;
    cin >> n;

    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    HeapSort(n, arr);

    OutputArray(n, arr);
}

void HeapSort(int n, int* Arr)
{
    BuildHeap(n, Arr);
    int heapSize = n;
    for (int i = 0; i < n; i++)
    {
        swap(Arr[0], Arr[n - 1 - i]);
        heapSize--;
        SiftDown(0, heapSize, Arr);
    }
}

void BuildHeap(int n, int* Arr)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        SiftDown(i, n, Arr);
    }
}

void SiftUp(int i, int* Arr)
{
    while (Arr[i] > Arr[(i - 1) / 2])
    {
        swap(Arr[i], Arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void SiftDown(int i, int n, int* Arr)
{
    int j = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && Arr[j] < Arr[leftChild])
    {
        j = leftChild;
    }
    if (rightChild < n && Arr[j] < Arr[rightChild])
    {
        j = rightChild;
    }
    if (i != j)
    {
        swap(Arr[i], Arr[j]);
        SiftDown(j, n, Arr);
    }
}

void OutputArray(int n, int* Arr)
{
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

void DrawHeap(int* Arr, int n)
{
    int lg = log2(n);
    
    for (int k = 0; k < pow(2, lg); k++)
    {
        cout << "  ";
    }
    cout << Arr[0] << "\n";

    for (int i = 1; i < lg + 1; i++)
    {
        for (int k = 0; k < pow(2, lg - i) - 1; k++)
        {
            cout << "  ";
        }

        for (int j = 0; j < pow(2, i); j++)
        {
            if (int(pow(2, i) - 1 + j) >= n)
            {
                break;
            }
            cout << Arr[int(pow(2, i)) - 1 + j];

            for (int k = 0; k < pow(2, lg - i + 1); k++)
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}