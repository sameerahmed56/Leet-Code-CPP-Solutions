class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> mp;
        for(auto a: matches){
            mp[a[0]].first++;
            mp[a[1]].second++;
        }
        vector<vector<int>> ans(2);
        for(auto it  = mp.begin(); it!=mp.end(); it++){
            if(it->second.second == 0){
                ans[0].push_back(it->first);
            }
            else if(it->second.second == 1){
                ans[1].push_back(it->first);
            }
        }
        return ans;
    }
};