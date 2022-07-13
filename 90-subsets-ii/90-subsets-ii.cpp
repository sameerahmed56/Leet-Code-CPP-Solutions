class Solution {
    void findSubset(vector<int>& arr, int ind, vector<int>&ds, vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int i = ind; i<arr.size(); i++){
            if(i!=ind && arr[i] ==  arr[i-1]) continue;
            ds.push_back(arr[i]);
            findSubset(arr, i+1, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubset(nums,0,ds,ans);
        return ans;
    }
};