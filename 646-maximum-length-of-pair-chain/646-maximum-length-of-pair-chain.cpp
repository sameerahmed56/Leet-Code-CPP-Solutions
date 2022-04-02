class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size(), ans = 0;
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            int count = 0;
            for(int j=i+1;j<n;j++){
                if(pairs[i][1] < pairs[j][0]) count = max(count,dp[j]);
            }
            dp[i] = count + 1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};