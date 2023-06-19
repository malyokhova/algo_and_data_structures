#include <iostream>
using namespace std;

void InputArray(int*, int);
void CountingSort(int*, int*, int);
string Compare(int*, int*, int);

int main()
{
    const int size1 = 1000;
    const int size2 = 1000;

    int n1, Arr1[size1];
    cin >> n1;
    InputArray(Arr1, n1);

    int n2, Arr2[size2];
    cin >> n2;
    InputArray(Arr2, n2);

    int result2[size2] = { 0 };
    CountingSort(Arr2, result2, n1);

    int result1[size1] = { 0 };
    CountingSort(Arr1, result1, n1);

    //for (int i = 0; i < n1; i++)
    //{
    //    if (result2[Arr1[i]] == 1)
    //    {
    //        result2[Arr1[i]] = 0;
    //    }
    //    else
    //    {
    //        result2[Arr1[i]] = 1;
    //    }
    //}

    cout << Compare(result1, result2, n2);

    return 0;
}

void InputArray(int* Array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> Array[i];
    }
}

void CountingSort(int* Array, int* result, int size)
{
    for (int i = 0; i < size; i++)
    {
        result[Array[i]] = 1;
    }
}

string Compare(int* Array1, int* Array2, int size)
{
    bool like = false;
    for (int i = 0; i < size; i++)
    {
        if (Array1[i] == Array2[i])
        {
            like = true;
        }
        else
        {
            return "NO";
        }
    }

    if (like)
    {
        return "YES";
    }
}

