vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{

    vector<vector<int>> diff;

    map<int, int> mp1;
    for (int i = 0; i < nums1.size(); i++)
    {

        mp1[nums1[i]]++;
    }

    map<int, int> mp2;
    for (int i = 0; i < nums2.size(); i++)
    {

        mp2[nums2[i]]++;
    }

    vector<int> tmp_nums1;
    for (int i = 0; i < nums1.size(); i++)
    {
        int var = nums1[i];
        if (mp2.find(var) == mp2.end() && mp1[var] != 0)
        {
            tmp_nums1.push_back(nums1[i]);
            mp1[var] = 0;
        }
    }
    diff.push_back(tmp_nums1);

    vector<int> tmp_nums2;
    for (int i = 0; i < nums2.size(); i++)
    {
        int var = nums2[i];
        if (mp1.find(var) == mp1.end() && mp2[var] != 0)
        {
            tmp_nums2.push_back(nums2[i]);
            mp2[var] = 0;
        }
    }
    diff.push_back(tmp_nums2);

    return diff;
}