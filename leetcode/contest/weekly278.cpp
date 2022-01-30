// ans 1

int findFinalValue(vector<int> &nums, int original)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < n)
    {
        if (original == nums[i])
            original *= 2, i++;
        else if (original > nums[i])
            i++;
        else
            break;
    }

    return original;
}

// ans 2
vector<int> maxScoreIndices(vector<int> &nums)
{
    int rightOne = accumulate(begin(nums), end(nums), 0), leftZero = 0, maxScore = 0;
    vector<int> res;
    for (int i = 0; i <= nums.size(); i++)
    {

        if (rightOne + leftZero > maxScore)
        {
            maxScore = rightOne + leftZero;
            res.clear();
            res.push_back(i);
        }

        else if (rightOne + leftZero == maxScore)
            res.push_back(i);

        if (i != nums.size())
        {
            if (nums[i] == 0)
                leftZero++;
            if (nums[i] == 1)
                rightOne--;
        }
    }
    return res;
}