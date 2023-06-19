#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char num;
    struct Node* next;
};

void Push(Node**, char);
char Pop(Node**);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node* head;
    head = nullptr;
    string str;
    //bool balance;
    int balance;

    int i = 0;
    do
    {
        str = "";
        getline(cin, str);
        i = 0;
        //balance = true;
        balance = 0;

        while (str[i] != '\n')
        {
            if (str[i] == '\0')
            {
                break;
            }

            if (str[i] == '(' || str[i] == '[')
            {
                Push(&head, str[i]);
                balance++;
            }
            else if (str[i] == ')')
            {
                if (head == nullptr)
                {
                    //balance = false;
                    balance = -1;
                    break;
                }

                if (head->num == '(')
                {
                    Pop(&head);
                    balance--;
                }
                else
                {
                    //balance = false;
                    balance = -1;
                    break;
                }
            }
            else
            {
                if (head == nullptr)
                {
                    //balance = false;
                    balance = -1;
                    break;
                }

                if (head->num == '[')
                {
                    Pop(&head);
                    balance--;
                }
                else
                {
                    //balance = false;
                    balance = -1;
                    break;
                }
            }

            i++;
        }

        if (str == "")
        {
            break;
        }

        //if (balance)
        if (balance == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        head = nullptr;
    } while (str != "");
    
    return 0;
}

void Push(Node** head, char parenthesis)
{
    if (*head == nullptr)
    {
        *head = new Node();
        (*head)->num = parenthesis;
        (*head)->next = nullptr;
    }
    else
    {
        Node* temp = *head;
        *head = new Node();
        (*head)->num = parenthesis;
        (*head)->next = temp;
    }
}

char Pop(Node** head) // получить и убрать первый элемент
{
    char result = (*head)->num;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;

    return result;
}