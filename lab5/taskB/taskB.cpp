#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
	int level;
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


int** InputArray(int, int, int**);
int RootSearch(int, int, int**);
Node* Insert(int**, int, int);
bool IsBinarySearchTree(Node*);
bool Check(Node*, Node*, Node*);
void Push(StackNodePosition**, NodeAndPos*);
NodeAndPos* Top(StackNodePosition*);
void Pop(StackNodePosition**);


int main()
{
	const int m = 3;

	int n;
	cin >> n;
	if (n <= 0)
	{
		cout << "YES\n";

		return 0;
	}

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	arr = InputArray(n, m, arr);

	int rootI = RootSearch(n, m, arr);

	Node* root = Insert(arr, rootI, n);

	if (IsBinarySearchTree(root))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}

	return 0;
}

void Push(StackNodePosition** tale, NodeAndPos* nodeAndPos)
{
	if (*tale == nullptr)
	{
		*tale = new StackNodePosition;
		(*tale)->prev = nullptr;
		(*tale)->value = nodeAndPos;
	}
	else
	{
		StackNodePosition* newItem = new StackNodePosition;
		newItem->prev = *tale;
		newItem->value = nodeAndPos;
		*tale = newItem;
	}
}

NodeAndPos* Top(StackNodePosition* tale)
{
	return tale->value;
}

void Pop(StackNodePosition** tale)
{
	auto temp = (*tale);
	*tale = (*tale)->prev;
	delete temp;
}

int** InputArray(int n, int m, int** Array)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Array[i][j];
		}
	}

	return Array;
}

int RootSearch(int countLines, int m, int** Array)
{
	int sumAndRoot = 0;
	for (int i = 0; i < countLines; i++)
	{
		sumAndRoot += i + 1;
		sumAndRoot -= Array[i][m - 2];
		sumAndRoot -= Array[i][m - 1];
	}

	return sumAndRoot - 1;
}

Node* Insert(int** Array, int iNum, int size)
{
	StackNodePosition* tale = nullptr;

	Node* root = new Node;
	Push(&tale, new NodeAndPos{ root, iNum });

	while (tale)
	{
		auto nodeAndPos = Top(tale);
		Node* temp = nodeAndPos->node;
		iNum = nodeAndPos->position;
		Pop(&tale);
		delete nodeAndPos;
		temp->value = Array[iNum][0];

		if (Array[iNum][2] > 0)
		{
			Node* rightChild = new Node;
			temp->rightChild = rightChild;
			rightChild->parent = temp;

			Push(&tale, new NodeAndPos{ rightChild, Array[iNum][2] - 1 });
		}
		else
		{
			temp->rightChild = nullptr;
		}
		if (Array[iNum][1] > 0)
		{
			Node* leftChild = new Node;
			temp->leftChild = leftChild;
			leftChild->parent = temp;

			Push(&tale, new NodeAndPos{ leftChild, Array[iNum][1] - 1 });
		}
		else
		{
			temp->leftChild = nullptr;
		}
	}

	return root;
}

bool IsBinarySearchTree(Node* root)
{
	Node* min = root;
	Node* max = root;

	while (min->leftChild != nullptr)
	{
		min = min->leftChild;
	}

	while (max->rightChild != nullptr)
	{
		max = max->rightChild;
	}

	return Check(root->leftChild, min, root) && Check(root->rightChild, root, max);
}

bool Check(Node* current, Node* min, Node* max)
{
	if (current == nullptr)
	{
		return true;
	}

	if (current->value <= min->value && current != min)
	{
		return false;
	}

	if (current->value >= max->value && current != max)
	{
		return false;
	}

	return Check(current->leftChild, min, current) && Check(current->rightChild, current, max);
}