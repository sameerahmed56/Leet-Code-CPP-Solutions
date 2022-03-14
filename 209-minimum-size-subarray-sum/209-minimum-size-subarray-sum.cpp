class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans =INT_MAX, start = 0, end =0, n=nums.size(), currSum = nums[0];
        bool updated = false;
        while(end < n-1 && start < n-1){
            if(currSum<target){
                currSum += nums[++end];
            }
            else{
                updated = true;
                ans = min(ans,end-start+1);
                if(start==end){
                    return ans;
                }
                currSum -= nums[start++];
                // cout <<  ans << " ";
            }
            // cout << start << "-" << end << " ";
        }
        while(currSum>=target){
            updated = true;
            ans = min(ans,end-start+1);
            currSum -= nums[start++];
        }
        return updated?ans:0;
    }
};