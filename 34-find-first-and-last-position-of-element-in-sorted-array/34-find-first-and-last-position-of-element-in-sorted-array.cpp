class Solution {
public:
    int searchLeft(vector<int>& nums, int target, int l, int r){
        while(r>=l){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                r = mid-1;
            }
            else l = mid+1;
        }
        return r+1;
    }
    int searchRight(vector<int>& nums, int target, int l, int r){
        while(r>=l){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                l = mid+1;
            }
            else r = mid-1;
        }
        return l-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int first = -1, last = -1, n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                ans[0] = searchLeft(nums,target,l,mid-1);
                ans[1] = searchRight(nums,target,mid+1,r);
                return ans;
            } 
            if(nums[mid]>target) r= mid-1;
            else l = mid+1;
        }
        return {-1,-1};
    }
};