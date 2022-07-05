class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        unordered_set<int> s;
        
        for(int i: nums) s.insert(i);
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            //minimum element to be searched for the purpose of comparing the next +1 value
            if(s.find(nums[i]-1) == s.end()){
                int j = nums[i]; // current value
                // next values while true do j++
                while(s.find(j)!=s.end())
                    j++;
                // max of previous ans and j - nums[i](-> smallest value)
                ans = max(ans,j-nums[i]);
            }
        }
        return ans;
    }
};