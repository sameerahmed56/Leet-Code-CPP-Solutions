class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int,int> mp;
        for(int i: nums1){
            mp[i] = 1;
        }
        for(int i: nums2){
            if (mp.find(i) != mp.end() && mp[i] >= 0){
                mp[i] =0;
            }
            else{
                mp[i]=-1;
            }
        }
        vector<vector<int>> ans(2);
        for(auto curr : mp){
            if(curr.second > 0){
                ans[0].push_back(curr.first);
            }
            else if(curr.second < 0){
                ans[1].push_back(curr.first);
            }
        }   
        return ans;
    }
};