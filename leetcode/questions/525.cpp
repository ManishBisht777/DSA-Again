int findMaxLength(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> map;
        int ans=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum+=(nums[i]==0)?-1:1;
            
            auto it=map.find(sum);
            
            if(sum==0)
            {
                if(ans<i+1)
                    ans=i+1;
            }
            else if(it!=map.end())
            {
                if(ans< i-it->second) ans=i-it->second;
            }
            else 
            {
                map.insert({sum,i});
            }
        }
        
        return ans;
        
        
    }