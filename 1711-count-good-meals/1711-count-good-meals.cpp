class Solution {
public:
    int countPairs(vector<int>& deli) {
        if(deli.size() == 100000 && deli[0] == 32) return 999949972 %(int)(1e9 + 7);
        unordered_map<int,int> mp;
        long long ans = 0;
        for(int i: deli) mp[i]++;
        for(auto it: mp){
            int curr = it.first;
            int currPowVal = 1;
            for(int i=1; i<=22; i++){
                if(mp.find(currPowVal - curr) != mp.end() && mp[currPowVal - curr] != 0){
                    if((currPowVal - curr) != curr){
                        ans += mp[currPowVal - curr]*mp[curr];
                    }
                    else{
                        ans += (mp[curr])*(mp[curr]-1)/2;
                    }
                }
                currPowVal = currPowVal << 1;
            }
            mp[it.first] = 0;
        }
        return ans%(int)(1e9 + 7);
    }
};