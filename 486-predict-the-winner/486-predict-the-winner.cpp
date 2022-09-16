class Solution {
public:
    int dp[21][21];
    int solve(vector<int>& nums, int l, int r, bool isFirst){
        if(l>r) return -1;
        
        if(l==r) return nums[l];
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        if(isFirst){
            dp[l][r] = max(nums[l] + solve(nums,l+1,r, !isFirst),nums[r] + solve(nums,l,r-1, !isFirst));
        }
        else{
            dp[l][r] = min(-nums[l] + solve(nums,l+1,r, !isFirst), - nums[r] + solve(nums,l,r-1, !isFirst));
        }
        return dp[l][r];
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,nums.size()-1, true) >= 0;
    }
};