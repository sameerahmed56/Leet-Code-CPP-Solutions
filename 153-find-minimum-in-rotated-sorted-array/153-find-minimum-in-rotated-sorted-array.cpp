class Solution {
public:
    int findMin(vector<int>& nums) {
        int  l=0,r=nums.size()-1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(l==r || (mid > 0  && nums[mid] < nums[mid-1])) return nums[mid];
            if(nums[l] <= nums[mid]){
                if(nums[r] > nums[mid]) return nums[l];
                if(l > 0 && nums[l] < nums[l-1]) r= mid-1;
                else l=mid+1;
            }
            else r = mid-1;
        }
        return l;
    }
};