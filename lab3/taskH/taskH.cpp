#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node* next;
    int countNextElem;
};

void Push(Node**, int);
int Peek(Node*);
int Pop(Node**);

int main()
{
    Node* head;
    head = nullptr;

    int n, k, num;
    cin >> n >> k;

    int meanPart = n / k;
    int count = 0, maxSum = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> num; 
        Push(&head, num);
        count++;
        if (count == meanPart)
        {
            if (maxSum == NULL)
            {
                maxSum = head->value + head->next->value;
            }
            else if(head->value + head->next->value >maxSum)
            {
                maxSum = head->value + head->next->value;
            }
        }
    }

    // 1 2 | 3 4 | 5 6 | 7 8 - head
    // maxSum = 15

    int sum, i = 0, afterThis;
    while (k)
    {
        sum = 0;
        for (i; i < n; i++)
        {
            sum += Peek(head);
            if (sum < maxSum && head->countNextElem > k)
            {
                afterThis = Pop(&head);
            }
            else
            {
                break;
            }
        }

        cout << afterThis << "/n";
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
        (*head)->countNextElem=0;
    }
    else
    {
        Node* temp = *head;
        *head = new Node();
        (*head)->value = num;
        (*head)->next = temp;
        (*head)->countNextElem = (*head)->next->countNextElem + 1;
    }
}

int Peek(Node* head) // получить первое значение (head)
{
    return head->value;
}

int Pop(Node** head)
{
    int result = (*head)->value;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;

    return result;
}

void MinMaxSum(Node* head, int& maxSum, int n, int k)
{
    // 1 2 | 3 4 | 5 6 | 7 8 - head
    // maxSum = 15

    int sum, i = 0;
    Node* elem, *p;
    elem = head;
    while (k)
    {
        sum = 0;
        for (i; i < n; i++)
        {
            sum += Peek(elem);
            if (sum < maxSum && head->countNextElem > k)
            {
                maxSum = sum;
                p = elem;
                elem = head->next;
            }
            else
            {
                k--;
                break;
            }
        }
    }
}