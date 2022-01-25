vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);

    long long product = 1;
    int zeroes = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            product *= nums[i];
        }
        else
        {
            zeroes++;
        }
    }

    if (zeroes > 1)
    {
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            ans[i] = product;
        }
        else if (zeroes)
            ans[i] = 0;
        else
        {
            ans[i] = product / nums[i];
        }
    }

    return ans;
}