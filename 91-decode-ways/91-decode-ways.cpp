class Solution {
public:
    int solve(string &s, int i,vector<int>& dp){
        int n = s.size();
        if(i == n){
            return 1;
        }
        if(i > n || s[i] - '0' == 0) return 0;
        if(dp[i] != -1) return dp[i];
        int sum = 0;
        if(s[i] - '0' == 1 && i < n-1){
            sum += solve(s,i+2, dp);
        }
        if(s[i] - '0' == 2 && i < n-1 && s[i+1] - '0' <= 6){
            sum += solve(s,i+2, dp); 
        }
        return dp[i] = sum + solve(s,i+1,dp);
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(s,0, dp);
    }
};