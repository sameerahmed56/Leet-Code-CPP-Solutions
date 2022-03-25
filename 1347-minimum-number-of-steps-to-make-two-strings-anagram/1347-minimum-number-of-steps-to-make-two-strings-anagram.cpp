class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int sum=0;
        for(auto i: s) mp[i]++;
        for(auto i: t) mp[i]--;
        
        for(auto i:mp){
            if(i.second<0) sum += i.second;
        }
        return abs(sum);    
    }
};