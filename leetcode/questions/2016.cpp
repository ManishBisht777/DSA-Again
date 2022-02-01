int maximumDifference(vector<int>& nums) {
        int ans=0;
        int maxans=INT_MIN;
        
        for(int i=1; i<nums.size();i++)
        {
            ans=max(0,ans+=nums[i]-nums[i-1]);
            maxans=max(maxans,ans);
        }
        
        if(maxans==0) return -1;
        return maxans;
    }