#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node* next;
};

void Push(Node**, int);
//int Peek(Node*);
int Pop(Node**);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node* head;
    head = nullptr;

    int n, num, count = 0;
    char command;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == '+')
        {
            cin >> num;
            Push(&head, num);
        }
        else if (command == '-')
        {
            cout << Pop(&head) << "\n";

        }
    }

    return 0;
}

void Push(Node** head, int num)
{
    if (*head == nullptr)
    {
        *head = new Node();
        (*head)->value = num;
        (*head)->next = nullptr;
    }
    else
    {
        Node* temp = *head;
        *head = new Node();
        (*head)->value = num;
        (*head)->next = temp;
    }
}

//int Peek(Node* head) // получить первое значение (head)
//{
//    return head->value;
//}

int Pop(Node** head) // получить и убрать первый элемент
{
    //int result = Peek(*head);
    int result = (*head)->value;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;

    return result;
}