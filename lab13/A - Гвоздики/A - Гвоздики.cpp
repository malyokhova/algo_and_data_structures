#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 1e3;

struct Point
{
    int x;
    int y;
};

int Hash(int, int);

int main()
{
    int n;
    cin >> n;

    Point* nail;
    int key, count = 0;
    vector<Point*> xHashTable(maxSize, nullptr);
    vector<Point*> yHashTable(maxSize, nullptr);
    for (int i = 0; i < n; i++)
    {
        nail = new Point;
        cin >> nail->x >> nail->y;
        key = Hash(nail->x, n);
        if (!xHashTable[key])
        {
            xHashTable[key] = nail;
        }
        else
        {
            if (xHashTable[key]->x == nail->x)
            {
                count++;
            }

            for (int j = 1; j < n; j++)
            {
                key += j;
                if (key < maxSize)
                {
                    if (!xHashTable[key])
                    {
                        xHashTable[key] = nail;
                    }
                }
                else
                {
                    key %= maxSize;
                    if (!xHashTable[key])
                    {
                        xHashTable[key] = nail;
                    }
                }
            }
        }

        key = Hash(nail->y, n);
        if (!yHashTable[key])
        {
            yHashTable[key] = nail;
        }
        else
        {
            if (yHashTable[key]->y == nail->y)
            {
                count++;         
            }

            for (int j = 1; j < n; j++)
            {
                key += j;
                if (key < maxSize)
                {
                    if (!yHashTable[key])
                    {
                        yHashTable[key] = nail;
                    }
                }
                else
                {
                    key %= maxSize;
                    if (!yHashTable[key])
                    {
                        yHashTable[key] = nail;
                    }
                }
            }
        }

        if (count == 3)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}

int Hash(int element, int n)
{
    return element % n;
}

//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct Point
//{
//    int x;
//    int y;
//};
//
//int Hash(int);
//
//int main()
//{
//    const int maxSize = 1e3;
//    int n;
//    cin >> n;
//
//    vector<Point> hashTableX(n);
//    for (int i = 0; i < n; i++)
//    {
//        Point nail;
//        cin >> nail.x >> nail.y;
//
//
//    }
//
//    int key, count = 0;
//    vector<int> counts(maxSize, 0);
//    for (int i = 0; i < n; i++)
//    {
//        key = Hash(nails[i]);
//        counts[key]++;
//    }
//
//    bool equal = true;
//    for (int i = 0; i < n; i++)
//    {
//        key = Hash(nails[i]);
//        if (counts[key] != 0)
//        {
//            equal = false;
//        }
//    }
//
//    if (equal)
//    {
//        cout << "YES";
//    }
//    else
//    {
//        cout << "NO";
//    }
//}
//
//int AddToHashTable(vector<Point> hashTable, Point element)
//{
//
//}
//
//int Hash1(int element)
//{
//    return element % 9;
//}
//
//int Hash2(int element)
//{
//    return element;
//}