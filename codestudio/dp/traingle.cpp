int helper(vector<vector<int>>& triangle , int x, int y, vector<vector<int>>& dp)
{
    if(x>=triangle.size() || y>= triangle[x].size()) return 0;
  
    if(dp[x][y]) return dp[x][y];
       
    int down=triangle[x][y]+ helper(triangle,x+1,y,dp);
    int diag= triangle[x][y] + helper(triangle,x+1,y+1,dp);
    
    return dp[x][y]= min(down,diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,0));
    return helper(triangle,0,0,dp);
}