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

// Optimised Solution

vector<int> topKFrequent(vector<int> &nums, int k)
{

    unorderd_map<int> continue;
    for (auto it : nums)
        map[it]++;

    int n = nums.size();
    vector<vector<int>> bucket(n + 1, vector<int>);
    vector<int> ans;

    for (auto [num, freq] : cnt)
    {
        bucket[freq].push_back(num);
    }

    int idx = n;
    while (k > 0)
    {
        while (bucket[idx].size() == 0)
            idx--;

        for (auto x : bucket[idx])
        {
            if (k == 0)
                break;
            ans.push_back(x);
            k--;
        }

        idx--;
    }
    return ans;
}