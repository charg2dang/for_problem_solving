#include <iostream>

using namespace std;

int main(void)
{
    int a;
    int b;
    cin >> a >> b;

    string stars = "";
    stars.reserve(a);

    for (int x{}; x < a; ++x)
    {
        stars += '*';
    }

    for (int y{}; y < b; ++y)
    {
        cout << stars << endl;
    }


    return 0;
}