#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        if (A + C >= B)
            cout << A + C << "\n";
        else
            cout << B << "\n";
    }
    return 0;
}
