class Solution {
    void findCombination(vector<int>& arr, int target, int ind, vector<int>&ds, vector<vector<int>>& ans){
        if(ind == arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(arr, target - arr[ind], ind, ds, ans);
            ds.pop_back();
        }
        findCombination(arr, target, ind+1, ds, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
         vector<vector<int>> ans;
        findCombination(candidates, target, 0, ds, ans);
        return ans;
    }
};