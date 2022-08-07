int dfs(int node,vector<int> adj[],vector<int>& vis)
    {
        if(vis[node]==1) return 0;
        vis[node]=1;
        
        int ans=0;
        for(auto it:adj[node])
        {
            if(vis[it]!=1) ans+=dfs(it,adj,vis);
        }
        
        return ans+1;
    }
    
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int> adj[n];
        
        vector<int> vis(n,0);
        
        for(auto it:restricted) vis[it]=1;
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
    }
        
        return dfs(0,adj,vis);
        
    }