#include <iostream>
using namespace std;

void CountingSort(int*, int, int);
int Calculate(int* Array, int size);

int main()
{
    const int maxSize = 100;
    int Arr[maxSize]{ 0 };

    int lastIndex = 0;
    int n;
    cin >> n;

    int first, last, count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> first >> last;
        if (last > lastIndex)
        {
            lastIndex = last;
        }
        CountingSort(Arr, first, last);
    }

    cout << Calculate(Arr, lastIndex + 1);

    return 0;
}

void CountingSort(int* Array, int first, int last)
{
    for (int i = first; i <= last; i++)
    {
        Array[i] = 1;
    }
}

int Calculate(int* Array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count += Array[i];
    }

    return count;
}
