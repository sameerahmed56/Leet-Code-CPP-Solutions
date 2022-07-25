class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int target = -nums[i];
            int front= i+1;
            int back = n-1;
            while(front<back){
                int sum = nums[front] + nums[back];
                if(sum > target){
                    back--;
                }
                else if(sum<target){
                    front++;
                }
                else{
                    ans.push_back({nums[i], nums[front], nums[back]});
                    int front_value = nums[front], back_value = nums[back];
                    while(front<=back && nums[front] == front_value) front++;
                    while(front<=back && nums[back] == back_value) back--;

                }
            }
            while(i+1<n && nums[i+1] == nums[i]){
                i++;
            }
            
        }
        return ans;
    }
};