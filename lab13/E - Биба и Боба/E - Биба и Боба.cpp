#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int maxSize = 1000;
    int n;
    cin >> n;
    int* S = new int[n];
    vector<int> counts(maxSize, 0);

    int key;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }

    int count = 0;    
    for (int i = 0; i < n; i++)
    {
        key = S[i] - i + n;
        counts[key]++;
        count += counts[key] - 1;
    }

    cout << count;

    delete[] S;
}