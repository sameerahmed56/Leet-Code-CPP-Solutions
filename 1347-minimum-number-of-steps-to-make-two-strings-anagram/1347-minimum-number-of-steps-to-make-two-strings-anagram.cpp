class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int sum=0, n= s.size();
        for(int i =0; i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto i:mp){
            if(i.second<0) sum += i.second;
        }
        return abs(sum);    
    }
};