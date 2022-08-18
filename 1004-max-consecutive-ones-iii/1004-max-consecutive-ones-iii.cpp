class Solution {
public:
    int countMaxOne(vector<int>& nums, int k, int i){
        int rem = k, count = 0, ans = 0, n = nums.size();
        while(i<n){
            if(nums[i] == 0){
                if(rem > 0){
                    rem--;
                    count++;
                }
                else{
                    ans = max(ans,count+ rem);
                    i = n;
                }
            }
            else{
                count++;
            }
            i++;
        }
        ans = max(ans,count+ rem);
        return  ans;
    }
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, ans = k;
        while(i < n){
            if(nums[i] == 1 && (i == 0 || nums[i-1] == 0)){
                ans = max(countMaxOne(nums,k,i), ans);
            }
            i++;
        }
        return min(ans,n);
    }
};