class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, i = 1, prev = nums[0], next = 0;
        while(i<nums.size()){
            int curr = nums[i];
            if(curr == prev){
                i++;
                continue;
            }
            while(i<nums.size() && nums[i] ==curr){
                i++;
            }
            if(i>=nums.size()) break;
            if(prev < curr && nums[i] < curr) ans++;
            else if(curr < prev && curr < nums[i]) ans++;
            prev = curr;
        }
        return ans;
    }
};