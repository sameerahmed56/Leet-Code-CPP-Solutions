class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ans;
        if(nums.size() == 0) return {};
        int start = nums[0], n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1){
                if(start != nums[i-1]){
                    ans.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                }
                else{
                    ans.push_back(to_string(start));
                }
                start = nums[i];
            }
        }
        if(start != nums[n-1]){
            ans.push_back(to_string(start) + "->" + to_string(nums[n-1]));
        }
        else{
            ans.push_back(to_string(start));
        }
        return ans;
    }
};