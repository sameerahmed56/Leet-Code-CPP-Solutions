class Solution {
public:
    int maxNonAdjacentSum(vector<int> &nums, int start, int end){
        int prev = 0, prev2 = 0;
        for(int i=start; i<=end; i++){
            int take = nums[i];
            if(i>start+1) take += prev2;
            int notTake = prev;
            int curi = max(take,notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        return max(maxNonAdjacentSum(nums,1,n-1), maxNonAdjacentSum(nums,0,n-2));
    }
};