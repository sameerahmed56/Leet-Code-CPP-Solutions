class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curr = nums[0], ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > curr) curr = nums[i];
            else{
                ans += curr+1-nums[i];
                curr = curr+1;
            }
        }
        return ans;
    }
};