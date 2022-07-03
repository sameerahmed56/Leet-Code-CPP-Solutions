class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), maxPrice = prices[n-1];
        vector<int> dp(n);
        for(int i=n-2; i>=0; i--){
            maxPrice = max(maxPrice,prices[i]);
            dp[i] = max(dp[i+1], maxPrice - prices[i]);
        }
        int minPrice = prices[0];
        for(int i=1; i<n; i++){
            minPrice = min(minPrice,prices[i]);
            dp[i] = max(dp[i-1], dp[i] + (prices[i] - minPrice));        
        }
        return dp[n-1];
    }
};