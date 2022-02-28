bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) { 
    return (a.second > b.second); 
} 
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans = 0, n = arr.size();
        map<int, int> mp;
        for(int curr: arr){
            mp[curr]++;
        }
        vector<pair<int, int>> vec;
        for (auto it = mp.begin(); it !=mp.end(); it++)
        {
            vec.push_back(make_pair(it->first, it->second));
        }
        sort(vec.begin(), vec.end(), sortByVal); 
        int sum = 0;
        
        for (int i = 0; i < vec.size(); i++)
        {
            if(sum>=n/2)
                break;
            
            sum += vec[i].second;
            ans++;
        }
        return ans;
    }
};