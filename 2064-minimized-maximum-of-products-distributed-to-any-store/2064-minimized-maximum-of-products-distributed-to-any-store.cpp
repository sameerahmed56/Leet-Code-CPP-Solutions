class Solution {
public:
    int ans = INT_MAX;
    bool isFeasible(vector<int>& nums, int n, int prod){
        int count = 0, maxValue = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]/prod > 0) maxValue = prod;
            count += nums[i]/prod;
            if(nums[i]%prod != 0){
                count++;
                maxValue = max(maxValue,nums[i]%prod);
            }
        }
        // cout << count << "-" << prod << ":" ;
        // cout << maxValue << " ";
        if(count <= n){
            ans = min(ans,maxValue);
        }
        return count<=n ;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int l=1,r=1e5;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isFeasible(nums,n,mid)){
                r= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};