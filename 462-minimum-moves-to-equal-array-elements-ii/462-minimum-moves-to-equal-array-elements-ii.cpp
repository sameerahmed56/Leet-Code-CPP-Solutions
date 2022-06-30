class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); 
        int mid = nums[n/2], ans = 0;
        for(int x: nums){
            ans += abs(mid-x);
        }
        return ans;
    }
};