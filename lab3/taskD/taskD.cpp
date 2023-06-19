#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
    int num;
    struct Node* next;
};

void Push(Node**, int);
int Pop(Node**);

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);*/

    Node* head;
    head = nullptr;

    string str;
    getline(cin, str, '\n');
    stringstream ss(str);
    
    int i = 0, wordInt, num1, num2, result;
    string word;
    while (ss >> word)
    {
        switch (word[0])
        {
        case '+':
        {
            num2 = Pop(&head);
            num1 = Pop(&head);
            result = num1 + num2;
            Push(&head, result);
            break;
        }
        case '-': 
        {
            if (word[1] != '\0')
            {
                wordInt = stoi(word);
                Push(&head, wordInt);
                break;
            }
            num2 = Pop(&head);
            num1 = Pop(&head);
            result = num1 - num2;
            Push(&head, result);
            break;
        }
        case '*': 
        {
            num2 = Pop(&head);
            num1 = Pop(&head);
            result = num1 * num2;
            Push(&head, result);
            break;
        }
        default:
            wordInt = stoi(word);
            Push(&head, wordInt);
            break;
        }

        i++;
    }

    cout << Pop(&head) << "\n";

    return 0;
}

void Push(Node** head, int num)
{
    if (*head == nullptr)
    {
        *head = new Node();
        (*head)->num = num;
        (*head)->next = nullptr;
    }
    else
    {
        Node* temp = *head;
        *head = new Node();
        (*head)->num = num;
        (*head)->next = temp;
    }
}

int Pop(Node** head)
{
    int result = (*head)->num;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;

    return result;
}