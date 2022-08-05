class Solution {
public:
    
    int helper(vector<int>& nums,int target,int idx,vector<int>& dp)
    {
        if(target==0) return 1;
        if(target<0) return 0;
        
        if(dp[target]) return dp[target];
        int ans=0;
        
        for(int i=idx;i<nums.size();i++)
        {
            if(nums[i]<=target)
                ans+=helper(nums,target-nums[i],idx,dp);
        }
        
        return dp[target]= ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<uint> dp(target + 1); dp[0] = 1;
	for (int i = 1; i <= target; i++) 
        for (auto& num : nums)     
            if (num <= i)  
				dp[i] += dp[i - num];   
    return dp[target];
    }
};