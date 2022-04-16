class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX, minVal = INT_MAX;
        for(int i: nums){
            if(abs(i) == minVal){
                ans = max(ans,i);
            }
            else if(abs(i)<minVal){
                ans=i;
                minVal = abs(i);
            }
        }
        return ans;
    }
};