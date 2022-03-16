class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        int h[1001]={};
        for(auto i:nums) h[i]++;
        while(o<=1000 && h[o])
            o=o<<1;
        return o;
    }
};