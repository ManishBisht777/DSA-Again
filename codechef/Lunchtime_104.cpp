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
        int N, K;
        cin >> N >> K;
        if (N == 1 && K == 1)
            cout << 1 << "\n";
        else
        {
            if (K < 2 || K > N)
            {
                cout << "-1"
                     << "\n";
            }
            else
            {
                int c = 0;
                for (int i = 0; i < K - 1; i++)
                {
                    cout << (i + 1) << " ";
                    c = i;
                }
                for (int i = 0; i < N - c - 1; i++)
                {
                    cout << (N - i) << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}