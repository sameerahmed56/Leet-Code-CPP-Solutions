class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int l, int r){
        if(l>r)return false;
        
        int left = nums[l] , right = nums[r], m = l+((r-l)/2), mid = nums[m];
        if(target == mid) return true;
        return binarySearch(nums,target, m + 1, r) || binarySearch(nums,target, l,m-1);
    }
//     int searchPivot(vector<int>& nums, int l, int r){
//         if(l>r)return -1;
//         int m = l+((r-l)/2);
//         if(nums[mid-1] > nums[mid]){
//             return mid;
//         }
        
//     }
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums,target, 0 , nums.size()-1);
    }
};