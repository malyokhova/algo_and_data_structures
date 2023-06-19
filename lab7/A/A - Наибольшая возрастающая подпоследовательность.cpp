#include <iostream>
using namespace std;

//int* FindLIS(int*, int, int*);

int main()
{
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << 0;
		return 0;
	}

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int k = 0;
	/*int* result = new int[n];
	result = FindLIS(arr, n, &k);*/

	int d[2000];
	int prev[2000];

	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		prev[i] = -1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				prev[i] = j;
			}
		}
	}

	int pos = 0;
	k = d[0];
	for (int i = 0; i < n; i++)
	{
		if (d[i] > k)
		{
			pos = i;
			k = d[i];
		}
	}

	int answer[2000];
	int i = 0;
	while (pos != -1)
	{
		answer[i] = arr[pos];
		pos = prev[pos];
		i++;
	}

	cout << k << endl;
	for (int i = k - 1; i >= 0; i--)
	{
		//cout << result[i] << " ";
		cout << answer[i] << " ";
	}
}

//int* FindLIS(int* Arr, int size, int* k)
//{
//	int d[2000];
//	int prev[2000];
//
//	for (int i = 0; i < size; i++)
//	{
//		d[i] = 1;
//		prev[i] = -1;
//		for (int j = 0; j < i; j++)
//		{
//			if (Arr[j] < Arr[i] && d[j] + 1 > d[i])
//			{
//				d[i] = d[j] + 1;
//				prev[i] = j;
//			}
//		}
//	}
//
//	int pos = 0;
//	*k = d[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (d[i] > *k)
//		{
//			pos = i;
//			*k = d[i];
//		}
//	}
//
//	int answer[2000];
//	int i = 0;
//	while (pos != -1)
//	{
//		answer[i] = Arr[pos];
//		pos = prev[pos];
//		i++;
//	}
//
//	return answer;
//}