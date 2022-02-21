#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        sort(A, A + N);

        int sum = 0;
        int cnt = N - 1;
        for (int i = N - 1; i >= 0; i--)
        {
            sum += A[i];
            if (sum < W)
                cnt--;
        }

        cout << cnt << "\n";
    }
    return 0;
}
