#include <iostream>
using namespace std;

struct Node
{
    float value;
    struct Node* next;
};

void Push(Node**, int);
int Pop(Node**);

int main()
{
    Node* head;
    head = nullptr;

    int n;
    float A, B;

    cin >> n >> A;
    int i;
    Push(&head, A);
    float p = A / 2 - 1;
    Push(&head, p);

    int temp;
    for (i = 0; i < n; i++)
    {
        B = 2 * (p + 1) - A;
        if (B > 0)
        {
            Push(&head, B);
            temp = p;
            p = B;
            A = temp;
        }
        else
        {
            i++;
            break;
        }
    }

    for (i; i < n; i++)
    {
        B = Pop(&head);
    }

    cout << B << "\n";

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

int Pop(Node** head)
{
    int result = (*head)->value;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;

    return result;
}