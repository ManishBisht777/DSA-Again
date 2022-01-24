vector<vector<int>> generateMatrix(int n)
{
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    vector<vector<int>> ans(n, vector<int>(n));
    int k = 1;
    while (true)
    {
        for (int i = left; i <= right; i++)
        {
            ans[top][i] = k++;
        }
        top++;
        if (left > right || top > bottom)
            break;

        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = k++;
        }
        right--;
        if (left > right || top > bottom)
            break;

        for (int i = right; i >= left; i--)
        {
            ans[bottom][i] = k++;
        }
        bottom--;
        if (left > right || top > bottom)
            break;

        for (int i = bottom; i >= top; i--)
        {
            ans[i][left] = k++;
        }
        left++;
        if (left > right || top > bottom)
            break;
    }

    return ans;
}