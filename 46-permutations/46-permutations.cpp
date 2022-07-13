class Solution {
    void recurPermute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool> freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                freq[i] = true;
                ds.push_back(nums[i]);
                recurPermute(nums,ds,ans,freq);
                freq[i] = false;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);
        recurPermute(nums,ds,ans,freq);
        return ans;
    }
};