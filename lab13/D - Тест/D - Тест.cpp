#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int isu;
	int points;
};

int Hash(int, int);
float Average(vector<Node>);
int MaxPoint(vector<Node>);
void DeleteStudent(vector<Node>, int);

int main()
{
    int m, q;
    cin >> m >> q;

    vector<vector<Node>> hashTable(m);
    char operation;
    int groupNum, key, isu, points;
    Node newNode;
	for (int i = 0; i < q; i++)
	{
        cin >> operation >> groupNum;
        key = Hash(groupNum, m);
        switch (operation)
        {
        case 'a': // 'a group' - найти средний балл в группе
            cout << Average(hashTable[key]) << "\n";
            break;
        case '-': // '- group isu' - удалить студента
            cin >> isu;
            DeleteStudent(hashTable[key], isu);
            break;
        case '+': // '+ group isu points' - добавить студента
            cin >> isu >> points;
            newNode.isu = isu;
            newNode.points = points;
            hashTable[key].push_back(newNode);
            break;
        case 'm': // 'm group' - найти студента с самым высоким баллом в группе
            cout << MaxPoint(hashTable[key]) << "\n";
            break;
        default:
            break;
        }
	}
}

int Hash(int groupNum, int size)
{
    return groupNum % size;
}

float Average(vector<Node> group) // средний балл
{
    int count = group.size();
    int score = 0;
    for (int i = 0; i < group.size(); i++)
    {
        if (group[i].points != -1)
        {
            score += group[i].points;
        }
        else
        {
            count--;
        }
    }

    return (float)score / count;
}

int MaxPoint(vector<Node> group)
{
    int max = -1;
    for (int i = 0; i < group.size(); i++)
    {
        if (max == -1)
        {
            max = group[i].points;
            continue;
        }
        
        if (group[i].points > max)
        {
            max = group[i].points;
        }
    }

    return max;
}

void DeleteStudent(vector<Node> group, int isu)
{
    for (int i = 0; i < group.size(); i++)
    {
        if (group[i].isu == isu)
        {
            group[i].isu = -1;
            group[i].points = -1;
        }
    }
}
