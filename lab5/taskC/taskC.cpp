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
void Push(StackNodePosition**, NodeAndPos*);
NodeAndPos* Top(StackNodePosition*);
void Pop(StackNodePosition**);
Node* CreateEmptyTree(Node**, int**, int);
Node* Leftmost(Node*);
Node* Next(Node*);

int main()
{
	const int m = 2;

	int n;
	cin >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	arr = InputArray(n, m, arr);
	Node** inputOrderArray = new Node * [n];
	int rootI = RootSearch(n, m, arr);

	Node* root = CreateEmptyTree(inputOrderArray, arr, rootI);

	Node* currentNode = Leftmost(root);
	int i = 1;
	while (currentNode)
	{
		currentNode->value = i;
		i++;
		currentNode = Next(currentNode);
	}

	for (int i = 0; i < n; i++)
	{
		cout << inputOrderArray[i]->value << ' ';
	}
	cout << '\n';

	return 0;
}

Node* CreateEmptyTree(Node** inputOrderArray, int** Array, int iNum)
{
	StackNodePosition* tale = nullptr;

	Node* root = new Node;
	root->parent = nullptr;
	Push(&tale, new NodeAndPos{ root, iNum });

	while (tale)
	{
		auto nodeAndPos = Top(tale);
		Node* temp = nodeAndPos->node;
		iNum = nodeAndPos->position;
		inputOrderArray[iNum] = temp; // Запоминаем узлы в порядке ввода, для финального вывода 
		Pop(&tale);
		delete nodeAndPos;

		if (Array[iNum][1] > 0)
		{
			Node* rightChild = new Node;
			temp->rightChild = rightChild;
			rightChild->parent = temp;

			Push(&tale, new NodeAndPos{ rightChild, Array[iNum][1] - 1 });
		}
		else
		{
			temp->rightChild = nullptr;
		}
		if (Array[iNum][0] > 0)
		{
			Node* leftChild = new Node;
			temp->leftChild = leftChild;
			leftChild->parent = temp;

			Push(&tale, new NodeAndPos{ leftChild, Array[iNum][0] - 1 });
		}
		else
		{
			temp->leftChild = nullptr;
		}
	}

	return root;
}

Node* Leftmost(Node* node)
{
	while (node->leftChild)
	{
		node = node->leftChild;
	}
	return node;
}

Node* Next(Node* currentNode)
{
	if (currentNode->rightChild)
	{
		return Leftmost(currentNode->rightChild);
	}

	Node* parent = currentNode->parent;
	while (parent && parent->rightChild == currentNode)
	{
		currentNode = parent;
		parent = parent->parent;
	}

	return parent;
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