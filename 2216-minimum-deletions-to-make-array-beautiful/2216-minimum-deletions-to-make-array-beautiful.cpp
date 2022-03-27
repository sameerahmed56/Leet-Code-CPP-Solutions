class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), curr = nums[0], ans = 0;
        for(int i = 1;i<n;i++){
            if((i-ans-1)%2==0 && nums[i] == curr ){
                ans++;
            }
            curr = nums[i];
        }
        return (n-ans)%2==0?ans:ans+1;
    }
};