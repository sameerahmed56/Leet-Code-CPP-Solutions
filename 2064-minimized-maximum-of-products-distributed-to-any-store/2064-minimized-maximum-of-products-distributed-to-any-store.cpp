class Solution {
public:
    bool isFeasible(vector<int>& nums, int n, int prod){
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count += (nums[i] + prod - 1) / prod;
        }
        return count<=n ;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int l=1,r=1e5;
        while(l<r){
            int mid = l + (r-l)/2;
            if(isFeasible(nums,n,mid)){
                r= mid;
            }
            else{
                l= mid+1;
            }
        }
        return l;
    }
};