bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), comp);

        int count = -1;
        vector<int> prev = intervals[0];

        for (auto it : intervals)
        {
            if (it[0] < prev[1])
                count++;
            else
                prev = it;
        }
        return count;
    }
};