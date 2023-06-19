#include <iostream>

using namespace std;

struct Node
{
    int value;
    struct Node* next;
};

void Push(Node*&, Node*&, int);
//void Output(Node*);
//int Peek(Node*);
int Pop(Node*&);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node* head, * tail;
    head = tail = nullptr;

    int n, num;
    char command;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == '+')
        {
            cin >> num;
            Push(tail, head, num);
        }
        else if (command == '-')
        {
            cout << Pop(head) << "\n";

        }
    }

    return 0;
}

void Push(Node* &tail, Node* &head, int num)
{
    if (head == nullptr || tail == nullptr)
    {
        tail = new Node();
        tail->value = num;
        tail->next = nullptr;
        head = tail;
    }
    else
    {
        tail->next = new Node();
        tail = tail->next;
        tail->value = num;
        tail->next = nullptr;
    }
}

//int Peek(Node* head) // получить первое значение (head)
//{
//    return head->value;
//}

int Pop(Node* &head) // получить и убрать первый элемент
{
    //int result = Peek(*head);
    int result = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;

    return result;
}

//void Output(Node* head)
//{
//    Node* temp = head;
//    while (temp != nullptr)
//    {
//        cout << temp->value << " -> ";
//        temp = temp->next;
//    }
//    cout << "NULL" << endl;
//}