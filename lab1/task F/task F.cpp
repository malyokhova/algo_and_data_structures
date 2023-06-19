#include <iostream>

using namespace std;

int main()
{
    struct fridge {
        float milk, meat;
        int cheese, yummy;
    };

    fridge Rich, Poor;
   /* cout << "Rich fridge:\n";
    cin >> Rich.milk;
    cin >> Rich.meat;
    cin >> Rich.cheese;
    cin >> Rich.yummy;

    cout << "\nPoor fridge\n";
    cin >> Poor.milk;
    cin >> Poor.meat;
    cin >> Poor.cheese;
    cin >> Poor.yummy;*/

    if (Rich.milk > Poor.milk)
    {
        Poor.yummy--;
        Rich.yummy++;
        Poor.milk += Rich.milk/2;
        Rich.milk /= 2;
    }

    //cout << "\n" << Rich.yummy << " " << Rich.milk << "\n" << Poor.yummy << " " << Poor.milk << endl;

    return 0;
}
