class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0, n = nums.size();
        for(auto x: nums) target += x;
        if(target & 1) return false;
        target = target / 2;
        vector<bool> prev(target + 1, 0);
        vector<bool> cur(target + 1, 0);
        prev[0] = 1, cur[0] = 1;
        for(int ind=1; ind<n; ind++){
            for(int k=1; k<=target; k++){
                bool notTake = prev[k];
                bool take = 0;
                if(nums[ind] <= k) take = prev[k-nums[ind]];
                cur[k] = take | notTake;
            }
            prev = cur;
        }
        return prev[target];
    }
};