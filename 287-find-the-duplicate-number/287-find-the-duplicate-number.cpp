class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n;i++){
            int temp = abs(nums[i]);
            if(nums[temp-1]< 0){
                return temp;
            }
            nums[temp-1] = -nums[temp-1];
        }
        return -1;
    }
};