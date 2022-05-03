int findUnsortedSubarray(vector<int> &nums)
{
    int st = -1, end = -1, max = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (max > nums[i])
        {
            if (st == -1)
                st = i - 1;

            while ((st - 1) >= 0 && nums[st - 1] > nums[i])
                st--;

            end = i + 1;
        }
        else
            max = nums[i];
    }

    return end - st;
}