class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res = "";        
        for(char c:s) freq[c]++;
        for(auto &it: freq){
            int n = it.second;
            bucket[n].append(n,it.first);
        }
        for(auto &x: bucket){
            if(x != ""){
                res = x + res;
            }
        }
        return res;
    }
};