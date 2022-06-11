int minOperations(vector<int> &nums, int x)
{

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    sum -= x;

    if (sum == 0)
        return nums.size();

    int i = 0, j = 0;
    int len = 0;

    int sum2 = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        sum2 += nums[j];

        while (sum2 > sum && i <= j)
            sum2 -= nums[i++];

        if (sum2 == sum)
            len = max(len, j - i + 1);
    }

    if (len == 0)
        return -1;

    return nums.size() - len;
}