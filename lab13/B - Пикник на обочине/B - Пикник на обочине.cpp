#include <iostream>
#include <vector>

using namespace std;

const int HASH_BASE = 101; // база для хэша
const int HASH_MOD = 1000000007; // модуль для хэша

// функция для вычисления хэша подстроки s[l..r]
int SubstringHash(const vector<int>& s, int l, int r)
{
    int hash_value = 0;
    int p = 1;

    for (int i = l; i <= r; i++)
    {
        hash_value = (hash_value + s[i] * p) % HASH_MOD;
        p = (p * HASH_BASE) % HASH_MOD;
    }

    return hash_value;
}

int main()
{
    int n;
    cin >> n;

    vector<int> s1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s1[i];
    }

    int m;
    cin >> m;

    vector<int> s2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s2[i];
    }

    // вычисляем хэши для всех префиксов s1 и s2
    vector<int> h1(n + 1), h2(m + 1);
    h1[0] = 0;
    h2[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        h1[i] = (h1[i - 1] * HASH_BASE + s1[i - 1]) % HASH_MOD;
    }

    for (int i = 1; i <= m; i++)
    {
        h2[i] = (h2[i - 1] * HASH_BASE + s2[i - 1]) % HASH_MOD;
    }

    int result = 0;

    // проходимся по всем подстрокам s1 и ищем максимальную длину общей подстроки
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int len = j - i;
            int hash_value1 = (h1[j] - h1[i] + HASH_MOD) % HASH_MOD;
            int hash_value2 = SubstringHash(s2, 0, len - 1);

            if (hash_value1 == hash_value2)
            {
                result = max(result, len);
            }
        }
    }

    cout << result << endl;

    return 0;
}