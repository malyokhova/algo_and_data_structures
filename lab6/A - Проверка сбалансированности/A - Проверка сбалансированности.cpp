#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
	int level;
	int balance;
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

void Push(StackNodePosition**, NodeAndPos*);
NodeAndPos* Top(StackNodePosition*);
void Pop(StackNodePosition**);
int** InputArray(int, int, int**);
Node** BuildTree(Node**, int**, int, int);
void UpdateLevel(Node**);
void PostorderTraversal(Node*);

int main()
{
	const int m = 3;

	int n;
	cin >> n;
	if (n <= 0)
	{
		cout << 0 << "\n";

		return 0;
	}

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	arr = InputArray(n, m, arr);


	Node* root;
	Node** balanceArray = BuildTree(&root, arr, 0, n);
	PostorderTraversal(root);

	for (int i = 0; i < n; i++)
	{
		cout << balanceArray[i]->balance << endl;
	}

	return 0;
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

Node** BuildTree(Node** root, int** Array, int iNum, int size)
{
	StackNodePosition* tale = nullptr;

	*root = new Node;
	(*root)->parent = nullptr;
	Push(&tale, new NodeAndPos{ *root, iNum });

	Node** balanceArray = new Node*[size];

	while (tale)
	{
		auto nodeAndPos = Top(tale);
		Node* temp = nodeAndPos->node;
		iNum = nodeAndPos->position;
		Pop(&tale);
		delete nodeAndPos;
		temp->value = Array[iNum][0];

		balanceArray[iNum] = temp;

		if (Array[iNum][1] == 0 && Array[iNum][2] == 0)
		{
			temp->leftChild = nullptr;
			temp->rightChild = nullptr;
		}
		else
		{
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
	}

	return balanceArray;
}

void PostorderTraversal(Node* root)
{
	if (root != nullptr)
	{
		PostorderTraversal(root->leftChild);
		PostorderTraversal(root->rightChild);
		int leftLevel, rightLevel;
		if (root->leftChild == nullptr)
		{
			leftLevel = -1;
		}
		else
		{
			leftLevel = root->leftChild->level;
		}

		if (root->rightChild == nullptr)
		{
			rightLevel = -1;
		}
		else
		{
			rightLevel = root->rightChild->level;
		}

		if (leftLevel > rightLevel)
		{
			root->level = leftLevel + 1;
		}
		else
		{
			root->level = rightLevel + 1;
		}

		root->balance = rightLevel - leftLevel;
	}
}
