#include <iostream>
#include <vector>
using namespace std;

int Hash(int);

int main()
{
    const int maxSize = pow(10,3);
    int n;
    cin >> n;

    int* A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int* B = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    int keyA, keyB, count = 0;
    vector<int> counts(maxSize, 0);
    for (int i = 0; i < n; i++)
    {
        keyA = Hash(A[i]);
        keyB = Hash(B[i]);
        counts[keyA]++;
        counts[keyB]--;
    }

    bool equal = true;
    for (int i = 0; i < n; i++)
    {
        keyA = Hash(A[i]);
        keyB = Hash(B[i]);
        if (counts[keyA] != 0 || counts[keyB] != 0)
        {
            equal = false;
        }
    }

    if(equal)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    delete[] A;
    delete[] B;
}

int Hash(int element)
{
    return element % 9;
}