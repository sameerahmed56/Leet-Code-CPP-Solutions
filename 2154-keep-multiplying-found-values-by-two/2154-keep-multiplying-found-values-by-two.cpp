class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> set;
        for(int curr: nums) set.insert(curr);
        while(set.count(original)>0) original = original<<1;
        return original;
    }
};