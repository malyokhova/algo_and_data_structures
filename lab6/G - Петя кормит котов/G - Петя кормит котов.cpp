#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
	int level;
	int balance;
	int index;
};

struct NodeAndPos
{
	Node* node;
	int position;
};

struct StackNodePosition
{
	NodeAndPos* value;
	StackNodePosition* prev;
};

void Increase(int* tree, int size, int itemIndex, int value);
void Decrease(int* tree, int size, int itemIndex, int value);
int SumRange(int* tree, int size, int leftItemIndex, int rightItemIndex);

int main()
{
	int n, q;
	cin >> n;
	cin >> q;

	if (n > 1)
	{
		n = pow(2, int(log2(n - 1)) + 1);
	}

	int treeSize = n * 2;
	int* segmentTree = new int[treeSize] {0};

	for (int i = 0; i < q; i++)
	{
		char event;
		int param1, param2;
		cin >> event;
		cin >> param1 >> param2;

		switch (event)
		{
		case '+':
		{
			Increase(segmentTree, treeSize, param1, param2);
			break;
		}

		case '-':
		{
			Decrease(segmentTree, treeSize, param1, param2);
			break;
		}


		case '?':
		{
			cout << SumRange(segmentTree, treeSize, param1, param2) << endl;
			break;
		}

		default:
		{
			break;
		}
		}
	}

	return 0;
}

void Increase(int* tree, int size, int itemIndex, int value)
{
	int i = size / 2 - 1 + itemIndex;
	tree[i] += value;

	i = (i - 1) / 2;
	do
	{
		tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
		i = (i - 1) / 2;
	} while (i > 0);
}

void Decrease(int* tree, int size, int itemIndex, int value)
{
	int i = size / 2 - 1 + itemIndex;
	if (tree[i] > value)
	{
		tree[i] -= value;
	}
	else
	{
		tree[i] = 0;
	}

	i = (i - 1) / 2;
	do
	{
		tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
		i = (i - 1) / 2;
	} while (i > 0);
}

int SumRange(int* tree, int size, int leftItemIndex, int rightItemIndex)
{
	int sum = 0;
	int left = size / 2 - 1 + leftItemIndex;
	int right = size / 2 - 1 + rightItemIndex;

	while (left <= right)
	{
		if (left % 2 != 1)
		{
			sum += tree[left];
		}
		if (right % 2 != 0)
		{
			sum += tree[right];
		}
		left = left / 2;
		right = (right - 2) / 2;
	}

	return sum;
}