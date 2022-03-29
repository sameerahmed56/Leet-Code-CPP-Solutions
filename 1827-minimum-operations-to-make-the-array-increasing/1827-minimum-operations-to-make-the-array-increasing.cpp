class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curr = nums[0], ans = 0;
        for(int i=1;i<nums.size();i++){
            curr = max(nums[i],curr+1);
            ans+= curr-nums[i];
        }
        return ans;
    }
};