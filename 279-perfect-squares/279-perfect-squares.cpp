class Solution {
public:
    vector<int> dp = vector<int>(10001,INT_MAX);
    int numSquares(int n) {
        if(n==0 || n==1 || n==2 || n==3 ) 
            return n;
        if(dp[n]!=INT_MAX){
            return dp[n];
        }
        for(int i =1; i*i<=n; i++){
            dp[n] = min(dp[n],1+ numSquares(n-i*i));
        }
        return dp[n];
    }
};
