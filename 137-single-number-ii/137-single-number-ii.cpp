class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i: nums) mp[i]++;
        for(auto x: mp) if(x.second==1) return x.first;
        return -1;
    }
};