int minMaxGame(vector<int> &nums)
{

    int n = nums.size();
    while (n > 1)
    {
        vector<int> newnums(n / 2, 0);
        int i = 0;

        for (int i = 0; i < n / 2; i++)
        {
            if (i % 2 == 0)
                newnums[i] = min(nums[2 * i], nums[2 * i + 1]);
            else
                newnums[i] = max(nums[2 * i], nums[2 * i + 1]);
        }

        n = n / 2;
        nums = newnums;
    }

    return nums[0];
}