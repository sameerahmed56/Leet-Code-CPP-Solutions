class Solution {
public:
    int findMinPath(vector<vector<int>>& triangle, int i,int j, vector<vector<int>>& dp){
        int n = triangle.size();
        if(i==n-1) return triangle[i][j];
        if(dp[i][j] != -1)  return dp[i][j];
        
        int down = triangle[i][j] + findMinPath(triangle,i+1,j, dp);
        int diag = triangle[i][j] + findMinPath(triangle,i+1,j+1, dp);
        
        dp[i][j] = min(down,diag);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for(int i=0; i<n; i++){
            vector<int> tmp(i+1,-1);
            dp[i] = tmp;
        }
        return findMinPath(triangle,0,0, dp);
    }
};