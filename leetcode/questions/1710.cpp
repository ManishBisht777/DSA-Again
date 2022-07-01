static bool myfun(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>> &arr, int size)
{

    sort(arr.begin(), arr.end(), myfun);

    int n = arr.size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (size <= 0)
            break;

        int box = min(arr[i][0], size);
        ans += box * arr[i][1];

        size -= arr[i][0];
    }

    return ans;
}