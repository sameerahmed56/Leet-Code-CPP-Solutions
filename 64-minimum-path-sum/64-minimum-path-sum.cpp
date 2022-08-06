class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,-1);
        for(int i=0; i<m; i++){
            vector<int> temp(n,INT_MAX);
            for(int j=0; j<n; j++){
                if(i==0 && j == 0){
                    temp[j] = grid[i][j];
                    continue;
                }
                int up = grid[i][j];
                int left = grid[i][j];
                if(i>0){
                    up += dp[j];
                    temp[j] = up;
                }
                if(j>0){
                    left += temp[j-1]; 
                    temp[j] = min(temp[j],left);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};