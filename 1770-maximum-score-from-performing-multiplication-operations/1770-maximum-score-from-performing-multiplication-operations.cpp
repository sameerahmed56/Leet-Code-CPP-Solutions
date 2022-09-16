class Solution {
public:
    int dp[1001][1001];
    int dfs(vector<int>& nums, vector<int>& multi, int l, int r, int i, vector<vector<int>>& dp){
        if(i==multi.size()) return 0;
        if(dp[l][i] != INT_MIN) return dp[l][i];
        
        int start = nums[l]*multi[i] + dfs(nums,multi,l+1,r,i+1, dp);
        int end = nums[r]*multi[i] + dfs(nums,multi,l,r-1,i+1, dp);
        dp[l][i] = max(start,end);
        return dp[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n = nums.size();
        int m = multi.size();
        vector<vector<int>> dp(m+2,vector<int>(m+2,INT_MIN));//         
        return dfs(nums,multi,0,nums.size()-1,0, dp);
    }
};