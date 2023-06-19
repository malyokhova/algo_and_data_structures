#include <iostream>
using namespace std;

struct Node {
	string value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
	bool owners[3];
};

struct StackNode
{
	Node* value;
	StackNode* prev;
};

void Push(StackNode**, Node*);
Node* Top(StackNode*);
void Pop(StackNode**);

void InsertAndCheck(Node*, Node*, int);
Node* CreateTree(string**, int, int);
void Preorder(Node*);
void Postorder(Node*);
void RecursivePostorder(Node*);
int* CalculateMarks(Node*);

int main()
{
	int n;
	cin >> n;
	string** arr = new string * [3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new string[n];
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	Node* root = CreateTree(arr, 0, n);

	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Node* newNode = new Node;
			newNode->value = arr[i][j];
			newNode->leftChild = nullptr;
			newNode->rightChild = nullptr;
			for (int i = 0; i < 3; i++)
			{
				newNode->owners[i] = false;
			}

			InsertAndCheck(root, newNode, i);
		}
	}

	int* res = CalculateMarks(root);
	for (int i = 0; i < 3; i++)
	{
		cout << res[i] << " ";
	}
	cout << "\n";

	return 0;
}

Node* CreateTree(string** Array, int friendNum, int size)
{
	if (size == 0)
	{
		return nullptr;
	}

	Node* root = new Node;
	root->parent = nullptr;
	root->leftChild = nullptr;
	root->rightChild = nullptr;
	root->value = Array[friendNum][0];
	root->owners[0] = true;
	root->owners[1] = false;
	root->owners[2] = false;

	for (int i = 1; i < size; i++)
	{
		Node* newNode = new Node;
		newNode->value = Array[friendNum][i];
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
		for (int i = 0; i < 3; i++)
		{
			newNode->owners[i] = false;
		}

		InsertAndCheck(root, newNode, friendNum);
	}

	return root;
}

void InsertAndCheck(Node* parent, Node* newNode, int friendNum)
{
	while (parent)
	{
		if (newNode->value.compare(parent->value) < 0) // Новое значение меньше по кодировке
		{
			if (parent->leftChild)
			{
				parent = parent->leftChild;
			}
			else
			{
				parent->leftChild = newNode;
				newNode->parent = parent;
				newNode->owners[friendNum] = true;
				break;
			}
		}
		else if (newNode->value.compare(parent->value) > 0) // Новое значение больше по кодировке
		{
			if (parent->rightChild)
			{
				parent = parent->rightChild;
			}
			else
			{
				parent->rightChild = newNode;
				newNode->parent = parent;
				newNode->owners[friendNum] = true;
				break;
			}
		}
		else // Равны, значит такое значение уже есть в дереве
		{
			parent->owners[friendNum] = true;
			break;
		}
	}
}

int* CalculateMarks(Node* root)
{
	if (!root)
	{
		return nullptr;
	}

	int* marks = new int[3] {0};

	StackNode* stack = nullptr;
	Push(&stack, root);

	while (stack)
	{
		auto temp = Top(stack);
		Pop(&stack);

		bool isAllOwners = true, isOneOwner = false;
		for (int i = 0; i < 3; i++)
		{
			isAllOwners = isAllOwners && temp->owners[i];
			isOneOwner = isOneOwner ^ temp->owners[i];
		}
		if (!isAllOwners)
		{
			if (isOneOwner)
			{
				for (int i = 0; i < 3; i++)
				{
					if (temp->owners[i])
					{
						marks[i] += 3;
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (temp->owners[i])
					{
						marks[i] += 1;
					}
				}
			}
		}

		if (temp->rightChild)
		{
			Push(&stack, temp->rightChild);
		}
		if (temp->leftChild)
		{
			Push(&stack, temp->leftChild);
		}
	}
	return marks;
}

void Push(StackNode** tale, Node* node)
{
	if (*tale == nullptr)
	{
		*tale = new StackNode;
		(*tale)->prev = nullptr;
		(*tale)->value = node;
	}
	else
	{
		StackNode* newItem = new StackNode;
		newItem->prev = *tale;
		newItem->value = node;
		*tale = newItem;
	}
}

Node* Top(StackNode* tale)
{
	return tale->value;
}

void Pop(StackNode** tale)
{
	auto temp = (*tale);
	*tale = (*tale)->prev;
	delete temp;
}