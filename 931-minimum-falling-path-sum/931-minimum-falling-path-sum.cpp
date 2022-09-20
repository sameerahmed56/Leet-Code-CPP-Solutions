class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n = m.size();
        vector<int> dp(n,0);
        for(int i=0; i<n; i++){
            dp[i] = m[0][i];
        }
        for(int i=1; i<n; i++){
            vector<int> temp(n,0);
            for(int j=0; j<n; j++){
                if(j==0){
                    temp[j] = m[i][j] + min({dp[j], dp[j+1]});
                }
                else if(j==n-1){
                    temp[j] = m[i][j] + min({dp[j], dp[j-1]});
                }
                else{
                    temp[j] = m[i][j] + min({dp[j], dp[j-1], dp[j+1]});
                }
            }
            dp = temp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};