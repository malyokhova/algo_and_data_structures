//сортировка подсчетом

#include <iostream>
using namespace std;

int main()
{
    int n; 
    cin >> n;

    char letter;
    int size = 26;
    char arr[26] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> letter;
        arr[letter - 132]++;
    }

    string str;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] / 2 != 0)
        {
            while (arr[i] != 0)
            {
                str.push_back(i + 132);
            }
        }
        else if(arr[i]/2==1)
        {

        }
    }

    return 0;
}