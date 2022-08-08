class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>> dp(n);
        for(int i=0; i<n; i++){
            vector<int> tmp(i+1,-1);
            dp[i] = tmp;
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                
                int up = 1e9;
                int diag = 1e9;
                if(i==0 && j == 0){
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                if(i>0 && j <i) up = triangle[i][j] + dp[i-1][j];
                if(j>0 && i>0) diag = dp[i-1][j-1] + triangle[i][j];
                
                dp[i][j] = min(up,diag);
                
                if(i==n-1){
                    ans = min(dp[i][j],ans);
                }
            }
        }

        return ans;
    }
};