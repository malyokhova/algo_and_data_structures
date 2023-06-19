#include <iostream> 
#include <vector> 
using namespace std;

const int MAX_N = 1e5;

int main()
{
    int n; 
    cin >> n;
    vector<int> books(n);

    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }

    int index = 0, counter;
    for (int i = 1; i < n; i++)
    {
        if (books[index] > books[i])
        {
            index = i;
        }
        else if (books[index] == books[i])
        {
            counter = 1;
            while (counter < n)
            {
                if (books[(index + counter) % n] == books[(i + counter) % n])
                {
                    counter++;
                    continue;
                }

                if (books[(index + counter) % n] > books[(i + counter) % n])
                {
                    index = i;
                }

                break;
            }
        }
    }

    for (int i = index; i < n; i++)
    {
        cout << books[i] << " ";
    }

    for (int i = 0; i < index; i++)
    {
        cout << books[i] << " ";
    }
}