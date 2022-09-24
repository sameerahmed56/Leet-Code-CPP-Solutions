class Solution {
public:
    int solve(vector<int>& nums, int target, int ind, vector<unordered_map<int,int>>& dp){
        int n = nums.size();
        if(ind == n-1){
            int val = 0;
            if(nums[ind] == target) val++;
            if(-nums[ind] == target) val++;
            return val;
        }
        auto it = dp[ind].find(target);
        if(it != dp[ind].end()) return it->second;
        
        int pos = solve(nums,target-nums[ind],ind+1, dp);
        int neg = solve(nums,target+nums[ind],ind+1, dp);
        return dp[ind][target] = pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size() + 1);
        return solve(nums,target,0, dp);
    }
};