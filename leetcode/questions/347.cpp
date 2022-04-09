#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    vector<int> ans;
    priority_queue<pait<int, int>> pq;

    for (auto it : mp)
    {
        pq.push(make_pair(it.second, it.first));

        if (pq.size() > mp.size() - k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }

    return ans;
}