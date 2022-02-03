int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> sum;
        int count=0;
            
        for(auto i:nums1)
        {
            for(auto j:nums2)
            {
                sum[i+j]++;
            }
        }
        
        for(auto k:nums3)
        {
            for(auto l:nums4)
            {
                auto it=sum.find(-(k+l));
                if(it!=sum.end())
                {
                    count+=it->second;
                }
            }
        }
        
        return count;
        
    }