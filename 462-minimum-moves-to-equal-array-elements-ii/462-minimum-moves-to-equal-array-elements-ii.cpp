class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), mid = nums[(n - 1)/2], ans = 0;
        for(int x: nums){
            ans += abs(mid-x);
        }
        return ans;
    }
};