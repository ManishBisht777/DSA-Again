bool subsetsum(int sum, vector<int> nums, int idx, vector<vector<int>>& dp)
    {
        if(sum==0) return true;
        if(idx==0) return (nums[idx]==sum);
      
      if(dp[idx][sum]) return dp[idx][sum];
        
        bool nottake=subsetsum(sum,nums,idx-1,dp);
        
        bool take=false;
        if(nums[idx]<=sum) take=subsetsum(sum - nums[idx] , nums,idx-1,dp);
        
        return dp[idx][sum] = take|| nottake;
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        int totalsum=0;
        
        for(int i=0; i<nums.size() ;i++) totalsum+=nums[i];
        
        if(totalsum%2!=0) return false;
        totalsum/=2;
        
        vector<vector<bool>> dp(nums.size(),vector<bool>(totalsum+1,0));
        
        for(int i=0; i<nums.size();i++) dp[i][0]=true;
        if(nums[0]<=totalsum) dp[0][nums[0]]=true;
        
        for(int i=1; i<nums.size();i++)
        {
            for(int j=1;j <totalsum+1 ;j++)
            {
                bool nottake=dp[i-1][j];
        
                bool take=false;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];

                 dp[i][j] = take|| nottake;
            }
        }
        
        return dp[nums.size()-1][totalsum];
        
        
    }