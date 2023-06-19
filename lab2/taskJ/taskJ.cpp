#include <iostream>
using namespace std;

void OutputArray(int*, int);
void Swap(int* num1, int* num2);

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (int i = 2; i < n; i++)
	{
		Swap(&arr[i], &arr[i / 2]);
	}

	OutputArray(arr, n);

	return 0;
}

void OutputArray(int* Array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
}

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}