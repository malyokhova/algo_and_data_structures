#include <iostream>

using namespace std;

int main()
{
    int n, Arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }

    int min1 = Arr[0], min2 = Arr[1]; // min1 всегда минимальный, min2 следующий наименьший
    if (min1 > min2)  // проверяем, чтобы min1 всегда был меньше min2
    {
        int temp = min2;
        min2 = min1;
        min1 = temp;
    }

    for (int i = 2; i < n; i++) // поиск сразу двух наименьших элементов
    {
        if (Arr[i] < min1)
        {
            min2 = min1;
            min1 = Arr[i];
        }
        else if (Arr[i] < min2)
        {
            min2 = Arr[i];
        }
    }

    cout << "\n" << min1 << " " << min2 << endl;
    
    return 0;
}
