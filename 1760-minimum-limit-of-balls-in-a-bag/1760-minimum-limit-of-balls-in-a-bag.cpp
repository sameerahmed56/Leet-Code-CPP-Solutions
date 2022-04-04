class Solution {
public:
    bool isFeasible(vector<int>& nums, int operations, int balls){
        int count = 0;
        for(int i: nums){
            if(i%balls==0 && i != 0){
                count += i/balls;
                count--;
            }
            else{
                count += i/balls;
            }
        }
        return count<=operations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=1e9, ans= -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isFeasible(nums,maxOperations,mid)){
                ans = mid;
                r=mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};