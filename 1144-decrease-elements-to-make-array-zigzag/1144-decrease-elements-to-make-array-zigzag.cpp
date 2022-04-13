class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size(), evenCount = 0, oddCount = 0;
        for(int i=0;i<n;i++){
            int minElement = INT_MAX;
            if(i%2==0){
                if(i!=0){
                    minElement = min(minElement,nums[i-1]);
                }
                if(i!=n-1){
                    minElement = min(minElement,nums[i+1]);
                } 
                if(nums[i]>=minElement) evenCount+= nums[i]-minElement+1;
            }
            else{
                minElement = min(minElement,nums[i-1]);
                if(i!=n-1){
                    minElement = min(minElement,nums[i+1]);
                } 
                if(nums[i]>=minElement) oddCount+= nums[i]-minElement+1;
            }
        }
        return min(evenCount,oddCount);
    }
};