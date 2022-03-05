class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(), l =0, r=n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if((mid==0 || nums[mid] > nums[mid-1]) && (mid == n-1 || nums[mid] > nums[mid+1])){
                return mid;
            }
            if((mid !=0 && nums[mid] < nums[mid-1])){
                r=mid;
            }
            else if(mid != n-1 && nums[mid] < nums[mid+1]){
                l=mid+1;
            }
        }
        return l;
    }
};