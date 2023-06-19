#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node* next;
    int max;
};

void Push(Node**, int);
int Pop(Node**);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node* head, *current;
    head = nullptr;

    int n, num, max, count = 0;
    char command;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        switch (command)
        {
        case '+':
        {
            cin >> num;
            Push(&head, num);
            break;
        }
        case '-':
        {
            Pop(&head);
            break;
        }
        default:
            cin >> str;
            cout << head->max << "\n";
            break;
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
        (*head)->max = num;
    }
    else
    {
        Node* temp = *head;
        *head = new Node();
        (*head)->value = num;
        (*head)->next = temp;
        if (num > temp->max)
        {
            (*head)->max = num;
        }
        else
        {
            (*head)->max = temp->max;
        }
    }
}

int Pop(Node** head)
{
    int result = (*head)->value;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;

    return result;
}