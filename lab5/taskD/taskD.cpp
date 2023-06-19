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

Node* Search(Node*, int);
void Insert(Node*, Node*);
void Delete(Node**, Node*);
//Node* Next(Node*);
//Node* Prev(Node*);
Node* Next(Node*, int);
Node* Prev(Node*, int);

int main()
{
    Node* root = nullptr;
    Node* next,* prev;

    int num;
    string str, operation;
    Node* newNode = new Node;
    stringstream ss;
    do
    {
        str = "";
        getline(cin, str);
        ss.str(str);
        ss >> operation;
        if (operation == "insert")
        {
            ss >> num;
            if (root == nullptr)
            {
                root = new Node;
                root->value = num;
                root->leftChild = nullptr;
                root->rightChild = nullptr;
                root->parent = nullptr;
            }
            else
            {
                newNode = new Node;
                newNode->value = num;
                newNode->leftChild = nullptr;
                newNode->rightChild = nullptr;
                Insert(root, newNode);
            }
        }
        else if (operation == "delete")
        {
            ss >> num;
            Delete(&root, Search(root, num));
        }
        else if (operation == "exists")     
        {
            ss >> num;
            if (Search(root, num) == nullptr)
            {
                cout << "false\n";
            }
            else
            {
                cout << "true\n";
            }
        }
        else if (operation == "next")    
        {
            ss >> num;
            next = Next(root, num);
            if ( next == nullptr)
            {
                cout << "none\n";
            }
            else
            {
                cout << next->value << endl;
            }
        }
        else if (operation == "prev")     
        {
            ss >> num;
            prev = Prev(root, num);
            if (prev == nullptr)
            {
                cout << "none\n";
            }
            else
            {
                cout << prev->value << endl;
            }
        } 
        operation = "";
        ss.clear();
    } while (str != "");

    return 0;
}

Node* Search(Node* root, int num)
{
    if (root == nullptr || num == root->value)
    {
        return root;
    }
    else if (num < root->value)
    {
        return Search(root->leftChild, num);
    }
    else if (num > root->value)
    {
        return Search(root->rightChild, num);
    }
}

void Insert(Node* root, Node* newNode)
{
    while (root)
    {
        if (newNode->value < root->value)
        {
            if (root->leftChild)
            {
                root = root->leftChild;
            }
            else
            {
                root->leftChild = newNode;
                newNode->parent = root;
                break;
            }
        }
        else
        {
            if (root->rightChild)
            {
                root = root->rightChild;
            }
            else
            {
                root->rightChild = newNode;
                newNode->parent = root;
                break;
            }
        }
    }
}

void Delete(Node** root, Node* node)
{
    Node* parent = node->parent;
    if (parent == nullptr)
    {
        node = nullptr;
        root = nullptr;
        delete node;
    }
    else
    {
        if (node->leftChild == nullptr && node->rightChild == nullptr)
        {
            if (parent->leftChild == node)
            {
                parent->leftChild = nullptr;
            }
            if (parent->rightChild == node)
            {
                parent->rightChild = nullptr;
            }
            delete node;
        }
        else if (node->leftChild == nullptr || node->rightChild == nullptr)
        {
            if (node->leftChild == nullptr)
            {
                if (parent->leftChild == node)
                {
                    parent->leftChild = node->rightChild;
                }
                else
                {
                    parent->rightChild = node->rightChild;
                }
                node->rightChild->parent = parent;
            }
            else
            {
                if (parent->leftChild == node)
                {
                    parent->leftChild = node->leftChild;
                }
                else
                {
                    parent->rightChild = node->leftChild;
                }
                node->leftChild->parent = parent;
            }
        }
        else
        {
            Node* successor = Next(*root, node->value);
            //Node* successor = Next(node);
            node->value = successor->value;
            if (successor->parent->leftChild == successor)
            {
                successor->parent->leftChild = successor->rightChild;
            }
            if (successor->rightChild != nullptr)
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
}

Node* Next(Node* node)
{
    if (node->rightChild != nullptr)
    {
        while (node->leftChild != nullptr)
        {
            node = node->leftChild;
        }

        return node;
    }

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->rightChild)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* Prev(Node* node)
{
    if (node->leftChild != nullptr)
    {
        while (node->rightChild != nullptr)
        {
            node = node->rightChild;
        }

        return node;
    }

    Node* parent = node->parent;
    while (parent != nullptr && node == parent->leftChild)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

//Node* Next(Node* root, int num)
//{
//    if (root == nullptr)
//    {
//        return root;
//    }
//
//    if (num > root->value)
//    {
//        if (root->rightChild != nullptr)
//        {
//            return Next(root->rightChild, num);
//        }
//        else if (root->parent == nullptr || root->parent->value > num)
//        {
//            return root->parent;
//        }
//        else
//        {
//            return root->rightChild;
//        }
//    }
//    else if (num < root->value)
//    {
//        if (root->leftChild != nullptr)
//        {
//            return Next(root->leftChild, num);
//        }
//        else
//        {
//            return root;
//        }
//    }
//}
//
//Node* Prev(Node* root, int num)
//{
//    if (root == nullptr)
//    {
//        return root;
//    }
//
//    if (num < root->value)
//    {
//        if (root->leftChild != nullptr)
//        {
//            return Prev(root->leftChild, num);
//        }
//        else if (root->parent == nullptr || root->parent->value < num)
//        {
//            return root->parent;
//        }
//        else
//        {
//            return root;
//        }
//    }
//    else if (num > root->value)
//    {
//        if (root->rightChild != nullptr)
//        {
//            return Prev(root->rightChild, num);
//        }
//        else
//        {
//            return root;
//        }
//    }
//}