class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string, int> mp;
        int n = s.size();
        string cur = "";
        for(int i=0; i<n && i<10; i++){   
            cur += s[i];
        }
        mp[cur]++;
        for(int i=10; i<n ; i++){   
            cur += s[i];
            cur.erase(cur.begin());
            mp[cur]++;
        }
        for(auto x: mp){
            if(x.second > 1) ans.push_back(x.first);
        }
        return ans;
    }
};