class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long sum = 0, ans = 1;
        int count =0, n=nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        for(int a: nums){
            sum+=a;
        }
        sum+=k;
        int div = 0;
        for(int i=0;i<n;i++){
            div = sum/(n-i);
            int x = nums[i];
            if(x<div || i==n-1){
                if(k<div-x || i==n-1){
                    x+=k;
                    k=0;
                }
                else{
                    k-=div-x;
                    x+=div-x;
                }
            }
            ans *=x;
            ans = ans%1000000007;
            sum-=x;
        }
        return (int)ans;
    }
};