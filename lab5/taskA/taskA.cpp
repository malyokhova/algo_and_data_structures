#include <iostream>
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
int InsertAndHeight(Node**, int**, int, int);
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
        cout << 0 << "\n";

        return 0;
    }

    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    arr = InputArray(n, m, arr);

    int rootI = RootSearch(n, m, arr);
    //Node* root = InsertAndHeight(nullptr, arr, rootI, n);
    //cout << root->height << "\n";

	Node* root = new Node;
	cout << InsertAndHeight(&root, arr, rootI, n);

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

int InsertAndHeight(Node** root, int** Array, int iNum, int size)
{
	StackNodePosition* tale = nullptr;

	*root = new Node;
	(*root)->level = 1;
	Push(&tale, new NodeAndPos{ *root, iNum });

	int maxHeight = 1;

	while (tale)
	{
		auto nodeAndPos = Top(tale);
		Node* temp = nodeAndPos->node;
		iNum = nodeAndPos->position;
		Pop(&tale);
		delete nodeAndPos;
		temp->value = Array[iNum][0];

		if (Array[iNum][1] == 0 && Array[iNum][2] == 0)
		{
			temp->leftChild = nullptr;
			temp->rightChild = nullptr;

			if (temp->level > maxHeight)
			{
				maxHeight = temp->level;
			}
		}
		else
		{
			if (Array[iNum][2] > 0)
			{
				Node* rightChild = new Node;
				temp->rightChild = rightChild;
				rightChild->parent = temp;
				rightChild->level = temp->level + 1;

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
				leftChild->level = temp->level + 1;

				Push(&tale, new NodeAndPos{ leftChild, Array[iNum][1] - 1 });
			}
			else
			{
				temp->leftChild = nullptr;
			}
		}

	}

	return maxHeight;
}

//Node* Insert(Node* node, Node* parent, int** Array, int iNum, int size)
//{
//    if (node == nullptr)
//    {
//        node = new Node;
//    }
//    node->value = Array[iNum][0];
//    Node* newLeftNode = new Node;
//    Node* newRightNode = new Node;
//    int hleft = 1, hright = 1;
//    int count = 0;
//    do
//    {
//        for (int i = 1; i < 3; i++)
//        {
//            if (i == 1 && Array[iNum][i] > 0)
//            {
//                node->leftChild = newLeftNode;
//                count++;
//                hleft++;
//                break;
//            }
//            else
//            {
//                node->leftChild = nullptr;
//                break;
//            }
//
//            if (Array[iNum][2] > 0)
//            {
//                node->rightChild = newRightNode;
//                hright++;
//                count++;
//            }
//            else
//            {
//                node->rightChild = nullptr;
//            }
//
//            if (hleft > hright)
//            {
//                node->height = hleft;
//            }
//            else
//            {
//                node->height = hright;
//            }
//            node = newNode;
//            newNode = ;
//        }
//    } while (count < size);
//
//    return node;
//}
