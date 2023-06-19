#include <iostream>

using namespace std;

void OutputArray(int*, int);
void GenerationArray(int*, int, int, int, int, int, int);
void Swap(int*, int*);
int QuickSortAndSearch(int*, int, int, int);

int main()
{
	int n, k;
	cin >> n >> k;
	int A, B, C, a1, a2;
	cin >> A >> B >> C >> a1 >> a2;

	int* arr = new int[n];
	GenerationArray(arr, n, a1, a2, A, B, C);

	cout << QuickSortAndSearch(arr, 0, n - 1, k - 1); // сортируем и ищем элементу именно его место. k-1, потому что вводят порядковый номер элемента 

	return 0;
}

void OutputArray(int* Array, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
}

void GenerationArray(int* Array, int size, int a1, int a2, int A, int B, int C)
{
	Array[0] = a1;
	Array[1] = a2;
	for (int i = 2; i < size; i++)
	{
		Array[i] = A * Array[i - 2] + B * Array[i - 1] + C;
	}
}

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int QuickSortAndSearch(int* Array, int l, int r, int needIndex)
{
	int middle = (l + r) / 2;
	int pivot = Array[middle];
	int i = l, j = r;
	while (i <= j)
	{
		while (Array[i] < pivot)
		{
			i++;
		}

		while (Array[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Swap(&Array[i++], &Array[j--]);
		}
	}

	if (needIndex < j) // работаем в той части, где наш необходимый элемент находится. Необходимый в левой части
	{
		return QuickSortAndSearch(Array, l, j, needIndex);
	}
	else
	{
		if (needIndex > i) // работаем в той части, где наш необходимый элемент находится. Необходимый в правой
		{
			return QuickSortAndSearch(Array, i, r, needIndex);
		}
	}

	return Array[needIndex];
}
