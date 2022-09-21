class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size(), evenSum = 0;
        for(auto x: nums) if(x%2==0) evenSum += x;
        for(int i=0; i<n; i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            
            if(nums[ind]%2==0 ){
                if(val%2==0){
                    evenSum += val;  
                }
                else{
                    evenSum -= nums[ind];
                }
            }
            else if(val%2!=0){
                evenSum += nums[ind] + val;  
            }
            ans.push_back(evenSum);
            nums[ind] += val;
        }
        return ans;
    }
};