vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(!root) return ans;
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int> curr;
            
            for(int i=0; i<n ;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                curr.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            ans.push_back(curr);
        }
        
       reverse(ans.begin(),ans.end());
       return ans; 
    }