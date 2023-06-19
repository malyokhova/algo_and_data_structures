#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int value;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
};

Node* Push(Node**, int);
void Insert(Node*, Node*);
int ExtractMin(Node**);
void DecreaseKey(Node**, Node**, int);
void DeleteNode(Node**, Node*);
Node* Next(Node*, Node*);

int main()
{
    Node* root = nullptr;
    Node* operationArray[100] = { 0 };
    int operationIndex = 0;

    int pushNum, position, newValue;
    string str, operation;
    stringstream ss;
    do
    {
        str = "";
        getline(cin, str);
        ss.str(str);
        ss >> operation;
        if (operation == "push")
        {
            ss >> pushNum;
            operationArray[operationIndex] = Push(&root, pushNum);
        }
        else if (operation == "extract-min")
        {
            if (root != nullptr)
            {
                cout << ExtractMin(&root) << "\n";
            }
            else
            {
                cout << "*" << "\n";
            }
        }
        else if (operation == "decrease-key") // else        
        {
            ss >> position >> newValue;
            DecreaseKey(&root, &operationArray[position - 1], newValue);
        }

        operationIndex++;
        ss.clear();
    } while (operation != "");

    return 0;
}

Node* Push(Node** root, int num)
{
    if (*root == nullptr)
    {
        *root = new Node();
        (*root)->value = num;
        (*root)->leftChild = nullptr;
        (*root)->rightChild = nullptr;
        (*root)->parent = nullptr;

        return *root;
    }
    else
    {
        Node* newNode = new Node;
        newNode->value = num;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;
        Insert(*root, newNode);

        return newNode;
    }
}

void Insert(Node* root, Node* newNode)
{
    if (newNode->value < root->value)
    {
        if (root->leftChild != nullptr)
        {
            Insert(root->leftChild, newNode);
        }
        else
        {
            root->leftChild = newNode;
            newNode->parent = root;
        }
    }
    else if (newNode->value >= root->value)
    {
        if (root->rightChild != nullptr)
        {
            Insert(root->rightChild, newNode);
        }
        else
        {
            root->rightChild = newNode;
            newNode->parent = root;
        }
    }
}

int ExtractMin(Node** root)
{
    Node* minimum = *root;
    Node* nodeParent = *root;

    if (!minimum->leftChild)
    {
        *root = (*root)->rightChild;
    }
    else
    {
        while (minimum->leftChild)
        {
            minimum = minimum->leftChild;
        }

        if (minimum->rightChild)
        {
            while (minimum->rightChild)
            {
                minimum = minimum->rightChild;
            }
        }
    }

    int minValue = minimum->value;
    DeleteNode(root, minimum);
    return minValue;
}

void DecreaseKey(Node** root, Node** kPush, int newValue)
{
    Node** temp = kPush;
    *kPush = Push(root, newValue);
    DeleteNode(root, *kPush);
}

void DeleteNode(Node** root, Node* kPush)
{
    Node* parent = kPush->parent;
    if (kPush->leftChild == nullptr && kPush->rightChild == nullptr)
    {
        if (parent->leftChild == kPush)
        {
            parent->leftChild = nullptr;
        }
        if (parent->rightChild == kPush)
        {
            parent->rightChild = nullptr;
        }
        delete kPush;
    }
    else if (kPush->leftChild == nullptr || kPush->rightChild == nullptr)
    {
        if (kPush->leftChild == nullptr)
        {
            if (parent->leftChild == kPush)
            {
                parent->leftChild = kPush->rightChild;
            }
            else
            {
                parent->rightChild = kPush->rightChild;
            }
            kPush->rightChild->parent = parent;
        }
        else
        {
            if (parent->leftChild == kPush)
            {
                parent->leftChild = kPush->leftChild;
            }
            else
            {
                parent->rightChild = kPush->leftChild;
            }
            kPush->leftChild->parent = parent;
        }
    }
    else
    {
        Node* successor = Next(*root, kPush);
        kPush->value = successor->value;
        if (successor->parent->leftChild== successor)
        {
            successor->parent->leftChild = successor->rightChild;
        }
        if (successor->rightChild!= nullptr)
        {
            successor->rightChild->parent = successor->parent;
        }
        else
        {
            successor->parent->rightChild = successor->rightChild;
        }
        if (successor->rightChild != nullptr)
        {
            successor->rightChild->parent = successor->parent;
        }
    }
}

Node* Next(Node* root, Node* kPush)
{
    Node* current = root;
    Node* successor = root;
    if (current->value <= kPush->value)
    {
        successor = current;
        return Next(current->rightChild, kPush);
    }
    else if (current->value > kPush->value)
    {
        successor = current;
        return Next(current->leftChild, kPush);
    }

    return current;
}