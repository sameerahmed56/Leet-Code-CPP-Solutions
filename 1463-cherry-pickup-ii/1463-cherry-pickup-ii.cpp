class Solution {
public:
    int solve(vector<vector<int>>& grid,int i, int j1, int j2,vector<vector<vector<int>>>& dp){
        int n = grid.size(), m = grid[0].size();
        if(j1 <0 || j1 >= m || j2 < 0 || j2 >= m) return INT_MIN;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        int value = j1==j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                dp[i][j1][j2] = max(dp[i][j1][j2],value + solve(grid,i+1,j1+x,j2+y, dp));
            }
        }
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return solve(grid,0,0,m-1,dp);
    }
};