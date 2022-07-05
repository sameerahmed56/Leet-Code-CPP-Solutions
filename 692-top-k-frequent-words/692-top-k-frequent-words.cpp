class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(string s: words) mp[s]++;
        priority_queue< pair<int, string>> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
        int prev = pq.top().first;
        set<string> temp;
        while(!pq.empty() && ans.size() < k){
            if(pq.top().first == prev){
                temp.insert(pq.top().second);
            }
            else{
                ans.insert(ans.end(), temp.begin(), temp.end());
                prev = pq.top().first;
                temp.clear();
                temp.insert(pq.top().second);
            }
            pq.pop();
        }
        if(ans.size()<k){
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        ans.resize(k);
        return ans;
    }
};