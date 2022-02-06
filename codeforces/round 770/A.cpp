#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string str;
        string copy = str;
        int len = str.size();
        cout << str;
        cin >> str;

        for (int i = 0; i < len / 2; i++)
            swap(str[i], str[len - i - 1]);

        if (str == copy && K <= 1)
            cout << "1"
                 << "\n";

        else
            cout << "2"
                 << "\n ";
    }

    return 0;
}