class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<int> dp(n+1,1);
        for(int i =n-2;i>=0;i--){
            int mx = 0;
            for(int k=i+1; k < n;k++){
                if(nums[k] > nums[i]){
                    mx = max(mx,dp[k]);
                }
            }
            dp[i] = mx + 1;
            ans = max(dp[i],ans);
        }
        return ans;
    }
};