class Solution {
public:
    int findMinPath(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + findMinPath(grid,i-1,j, dp);
        int left = grid[i][j] + findMinPath(grid,i,j-1, dp);
        
        dp[i][j] = min(up, left);
        
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return findMinPath(grid,m-1,n-1, dp);
    }
};