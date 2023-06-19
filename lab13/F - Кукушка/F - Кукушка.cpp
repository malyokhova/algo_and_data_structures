#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 1e6;

int Hash1(string, int);
int Hash2(string, int);

int main()
{
    int n;

    cin >> n;

    string str;
    vector<pair<string, int>> hashTable1(MAX_SIZE, { "", 0 });
    vector<pair<string, int>> hashTable2(MAX_SIZE, { "", 0 });
    int key;
    pair<string, int> temp1, temp2;
    int score[3] = { 3 * n, 3 * n, 3 * n };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> str;
            key = Hash1(str, n);

            temp1 = hashTable1[key];
            hashTable1[key].first = str;
            hashTable1[key].second = i;
            if (temp1.first != "") // а тут коллизию надо проверять
            {
                key = Hash2(temp1.first, n); // тут может быть документ с другим названием, но с таким же хешем
                temp2 = hashTable2[key];
                hashTable2[key].first = temp1.first;
                hashTable2[key].second = temp1.second;
                if (temp2.first != "")
                {
                    score[i] -= 3;
                    score[temp2.second] -= 1;
                    score[temp1.second] -= 1; // что скажешь насчёт этого?
                }
                else
                {
                    score[i] -= 2;
                    score[temp1.second] -= 2;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << score[i] << " ";
    }
}

int Hash1(string str, int n)
{
    int p = 53;
    int m = MAX_SIZE + 9;
    int key = 0;
    long long p_pow = 1;
    for (int i = 1; i < str.size() + 1; i++)
    {
        key = (key + (str[i - 1] - '0' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return key % MAX_SIZE;
}

int Hash2(string str, int n)
{
    int p = 61;
    int m = MAX_SIZE + 7;
    int key = 0;
    long long p_pow = 1;
    for (int i = 1; i < str.size() + 1; i++)
    {
        key = (key + (str[i - 1] - '0' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return key % MAX_SIZE;
}