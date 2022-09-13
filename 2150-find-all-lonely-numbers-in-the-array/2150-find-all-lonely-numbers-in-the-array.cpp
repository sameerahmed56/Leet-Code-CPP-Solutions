class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x: nums) mp[x]++;
        vector<int> ans;
        for(auto &it: mp){
            if(!mp.count(it.first-1) && !mp.count(it.first+1) && it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};