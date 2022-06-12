 int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int curr=0;
        int ans=0;
        int l=0;
        
        for(int i=0; i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                int index=mp[nums[i]];
                while(l<=index)
                {
                    mp.erase(nums[l]);
                    curr-=nums[l++];
                }
                
            }
            mp[nums[i]]=i;
            curr+=nums[i];
            ans=max(ans,curr);
        }
        
        return ans;
    }