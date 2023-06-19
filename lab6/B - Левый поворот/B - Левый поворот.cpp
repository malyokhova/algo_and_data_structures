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

void Push(StackNodePosition**, NodeAndPos*);
NodeAndPos* Top(StackNodePosition*);
void Pop(StackNodePosition**);
int** InputArray(int, int, int**);
Node** BuildTree(Node**, int**, int, int);
void UpdateLevel(Node**);
void PostorderTraversal(Node*);
void PreorderTraversal(Node*, int**, int*);
Node* LeftRotate(Node*);
Node* RightRotate(Node*);
void FixHeight(Node*);
Node* Balance(Node*);

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
	Node** treeArray = BuildTree(&root, arr, 0, n);
	PostorderTraversal(root);
	root = Balance(root);

	int** result = new int* [n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new int[m];
	}

	int i = 0;
	PreorderTraversal(root, result, &i);

	cout << n << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
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

	Node** balanceArray = new Node * [size];

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

void PreorderTraversal(Node* node, int** result, int* i)
{
	if (node != nullptr)
	{
		node->index = *i + 1;
		result[*i][0] = node->value;

		if (node->parent != nullptr)
		{
			if (node->parent->leftChild == node)
			{
				result[node->parent->index - 1][1] = *i + 1;
			}
			else
			{
				result[node->parent->index - 1][2] = *i + 1;
			}
		}
		(*i)++;

		if (node->leftChild == nullptr)
		{
			result[node->index - 1][1] = 0;
		}
		else
		{
			PreorderTraversal(node->leftChild, result, i);
		}

		if (node->rightChild == nullptr)
		{
			result[node->index - 1][2] = 0;
		}
		else
		{
			PreorderTraversal(node->rightChild, result, i);
		}	
	}
}

//void UpdateLevel(Node** node)
//{
//	int leftLevel, rightLevel;
//	while ((*node)->parent != nullptr)
//	{
//		if ((*node)->parent->leftChild == *node)
//		{
//			leftLevel = (*node)->leftChild->level;
//			rightLevel = (*node)->rightChild->level;
//			if (leftLevel > rightLevel)
//			{
//				(*node)->parent->level = leftLevel + 1;
//			}
//			else
//			{
//				(*node)->parent->level = rightLevel + 1;
//			}
//		}
//		if ((*node)->parent->rightChild == *node)
//		{
//			leftLevel = (*node)->leftChild->level;
//			rightLevel = (*node)->rightChild->level;
//			if (leftLevel > rightLevel)
//			{
//				(*node)->parent->level = leftLevel + 1;
//			}
//			else
//			{
//				(*node)->parent->level = rightLevel + 1;
//			}
//		}
//		*node = (*node)->parent;
//		(*node)->balance = rightLevel - leftLevel;
//	}
//}

void FixHeight(Node* node)
{
	int leftLevel, rightLevel;
	if (node->leftChild != nullptr)
	{
		leftLevel = node->leftChild->level;
	}
	else
	{
		leftLevel = -1;
	}

	if (node->rightChild != nullptr)
	{
		rightLevel = node->rightChild->level;
	}
	else
	{
		rightLevel = -1;
	}

	if (leftLevel > rightLevel)
	{
		node->level = leftLevel + 1;
	}
	else
	{
		node->level = rightLevel + 1;
	}

	node->balance = rightLevel - leftLevel;
}

Node* LeftRotate(Node* root)
{
	Node* newRoot = root->rightChild;
	root->rightChild = newRoot->leftChild;
	newRoot->leftChild = root;

	if (root->parent != nullptr)
	{
		root->parent->leftChild = newRoot;
	}
	newRoot->parent = root->parent;
	root->parent = newRoot;
	if (root->rightChild != nullptr)
	{
		root->rightChild->parent = root;
	}

	FixHeight(root);
	FixHeight(newRoot);
	return newRoot;
}

Node* RightRotate(Node* root)
{
	Node* newRoot = root->leftChild;
	root->leftChild = newRoot->rightChild;
	newRoot->rightChild = root;

	if (root->parent != nullptr)
	{
		root->parent->rightChild = newRoot;
	}
	newRoot->parent = root->parent;
	root->parent = newRoot;
	if (root->leftChild != nullptr)
	{
		root->leftChild->parent = root;
	}

	FixHeight(root);
	FixHeight(newRoot);
	return newRoot;
}

Node* Balance(Node* node)
{
	if (node->balance == 2)
	{
		if (node->rightChild->balance < 0)
		{
			node->rightChild = RightRotate(node->rightChild);
		}
		return LeftRotate(node);
	}
	if (node->balance == -2)
	{
		if (node->leftChild->balance > 0)
		{
			node->leftChild = LeftRotate(node->leftChild);
		}
		return RightRotate(node);
	}
	return node;
}
