// ques 1

#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    int A, B, C;
    while (t--)
    {
        cin >> A >> B >> C;
        if (A > 50)
            cout << "A"
                 << "\n";
        else if (B > 50)
            cout << "B"
                 << "\n";
        else if (C > 50)
            cout << "C"
                 << "\n";
        else
            cout << "NOTA"
                 << "\n";
    }
    return 0;
}

// ques 2

#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    int K;
    while (t--)
    {
        cin >> K;
        cout << 52 % K << "\n";
    }
    return 0;
}

// ques 3

#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a, b = 0;
        cin >> a;
        while (a % 2 == 0)
        {
            a = a / 2;
            b += 1;
        }
        cout << b << "\n";
    }
    return 0;
}
