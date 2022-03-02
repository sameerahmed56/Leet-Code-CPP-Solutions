class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posInd = 0, negInd = 0, currI = 0, currJ = 1;
        while(posInd < n && negInd < n){
            if(posInd < n && nums[posInd] > 0){
                ans[currI] = nums[posInd];
                currI += 2;
            } 
            if(negInd < n && nums[negInd] < 0){
                ans[currJ] = nums[negInd];
                currJ += 2;
            } 
            posInd++;
            negInd++;
        }
        return ans;
    }
};
// [3,1,-2,-5,-8,-9,2,8,9,-4]
// [3,-2,1,-5,2,-9,9,-8,8,-4]