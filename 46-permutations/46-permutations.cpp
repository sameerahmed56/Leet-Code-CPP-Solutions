class Solution {
    void recurPermute(vector<int>& nums, vector<vector<int>>& ans, int ind){
        if(ind>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i],nums[ind]);
            recurPermute(nums,ans,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);
        recurPermute(nums,ans,0);
        return ans;
    }
};