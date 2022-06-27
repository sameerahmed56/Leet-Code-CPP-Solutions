class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x: nums) mp[x]++;
        int count = 0;
        for(auto i: mp){
            if(k==0){
                if(i.second>1) count++;
            }
            else if(mp.count(i.first - k)){
                count++;
            }
        }
        return count;
    }
};