class Solution {
public:
    vector<int> dp = vector<int>(31,-1);
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = fib(n-1) + fib(n-2);
        return dp[n];
    }
};