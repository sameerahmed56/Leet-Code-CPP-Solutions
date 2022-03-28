class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l< r){
            if(nums[l] < nums[r])return nums[l];
            int mid = l + (r - l) / 2;
            if(nums[l] == nums[mid])l++;
            else if (nums[mid]>=nums[l]) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};