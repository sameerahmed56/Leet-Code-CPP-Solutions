class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        for(int curr: nums){
            mp[curr]++;
        }
        vector<pair<int, int>> v;
        for(auto it=mp.begin();it!=mp.end();it++){
            v.push_back({it->second,it->first});
        }
        sort(v.begin(), v.end());
        int i =v.size()-1;
        while(k>0){
            ans.push_back(v[i].second);
            i--;
            k--;
        }
        return ans;   
    }
};