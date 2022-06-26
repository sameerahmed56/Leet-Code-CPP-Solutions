class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), maxElem = nums[0], minElem = nums[0], maxInd = 0, minInd = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < minElem){
                minElem = nums[i];
                minInd = i;
            }
            if(nums[i] > maxElem){
                maxElem = nums[i];
                maxInd = i;
            }
        }
        int start = min(maxInd, minInd), end = max(maxInd, minInd);
        int ans = end + 1;
        ans = min(n-start, ans);
        ans = min(start + n - end + 1, ans);
        return ans;
    }
};