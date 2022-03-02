class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans =0, n = words.size();
        for(int i=0;i<n;i++) if(words[i].substr(0, pref.size()) == pref) ans++;
        return ans;
    }
};