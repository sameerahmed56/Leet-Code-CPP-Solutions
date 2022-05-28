class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1, prev = nums[n], ind1 = -1, ind2 = -1;
        for(int i=n-1; i>=0;i--){
            if(nums[i] < prev){
                ind1 = i;
                break;
            }
            prev = nums[i];
        }
        if(ind1 == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n;i>=0;i--){
            if(nums[i] > nums[ind1]){
                ind2 = i;
                break;
            }
        }
        swap(nums[ind1],nums[ind2]);
        reverse(nums.begin() + ind1 + 1, nums.end());

    }
};