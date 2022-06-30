class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), minn = INT_MAX;
        long long sum = 0;
        for(int x: nums){
            sum += x;
            minn = min(minn,x);
        }
        return sum - (minn * n);

    }
};