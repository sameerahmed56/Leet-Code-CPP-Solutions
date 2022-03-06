class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i: nums1){
            mp[i]=1;
        }
        for(int i: nums2){
            if(mp[i]==1) mp[i]=2;
        }
        for(auto x: mp){
            if(x.second==2)
                ans.push_back(x.first);
        }
        return ans;
    }
};