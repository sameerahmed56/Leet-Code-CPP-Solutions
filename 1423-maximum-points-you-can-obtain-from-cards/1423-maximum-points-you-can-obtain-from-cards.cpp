class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0 , subSum = 0;
        for(int i=0;i<n;i++){
            if(i < n-k) subSum += cardPoints[i];
            totalSum += cardPoints[i];
        }
        int ans = totalSum - subSum;
        for(int i=0;i<k;i++){
            subSum = subSum + cardPoints[i+n-k] - cardPoints[i];
            ans = max(totalSum - subSum,ans);
        }
        return ans;
    }
};