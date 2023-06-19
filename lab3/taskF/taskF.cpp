#include <iostream>
using namespace std;

int* InputArray(int);
void BinarySearch(int, int, int*, int, int*, int*);
int BinarySearchFirst(int, int, int*, int);
int BinarySearchLast(int, int, int*, int);

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];

    arr = InputArray(n);

    int m;
    cin >> m;
    int num, numI, left, right, first, last;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        left = 0;
        right = n - 1;
        first = last = -1;
        BinarySearch(left, right, arr, num, &first, &last);

        cout << first + 1 << " " << last + 1 << "\n";
    }

    return 0;
}

int* InputArray(int n)
{
    int* Arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }

    return Arr;
}

void BinarySearch(int left, int right, int* Arr, int num, int* first, int* last)
{
    if (left > right)
    {
        *first = *last = -2;
        return;
    }

    int middle = (left + right) / 2;
    if (Arr[middle] > num)
    {
        BinarySearch(left, middle - 1, Arr, num, first, last);
    }
    else if (Arr[middle] < num)
    {
        BinarySearch(middle + 1, right, Arr, num, first, last);
    }
    else
    {
        *first = BinarySearchFirst(left, middle - 1, Arr, num);
        *last = BinarySearchLast(middle + 1, right, Arr, num);
    }
}

int BinarySearchFirst(int left, int right, int* Arr, int num)
{
    if (left >= right)
    {
        if (Arr[left] == num)
        {
            return left;
        }
        else
        {
            return left + 1;
        }
    }

    int middle = (left + right) / 2;
    if (Arr[middle] == num)
    {
        return BinarySearchFirst(left, middle - 1, Arr, num);
    }
    else if (Arr[middle] < num)
    {
        return BinarySearchFirst(middle + 1, right, Arr, num);
    }
}

int BinarySearchLast(int left, int right, int* Arr, int num)
{
    if (left >= right)
    {
        if (Arr[right] == num)
        {
            return right;
        }
        else
        {
            return right - 1;
        }
    }

    int middle = (left + right) / 2;
    if (Arr[middle] == num)
    {
        return BinarySearchLast(middle + 1, right, Arr, num);
    }
    else if (Arr[middle] > num)
    {
        return BinarySearchLast(left, middle - 1, Arr, num);
    }
}