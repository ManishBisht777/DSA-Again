vector<int> getRow(int row)
{
    vector<int> ans(row + 1);

    ans[0] = 1;

    for (int i = 0; i <= row; i++)
    {
        for (int j = i; j > 0; j--)
        {
            ans[j] = ans[j - 1] + ans[j];
        }
    }
    return ans;
}