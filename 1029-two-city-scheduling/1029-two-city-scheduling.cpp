class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> diff;
        int n=costs.size();
        for(int i=0;i<n;i++) 
            diff.push_back({abs(costs[i][0]-costs[i][1]),i});
        
        sort(diff.begin(),diff.end());
        
        int ans=0,aCount = n/2, bCount =n/2;
        for(int i=n-1;i>=0;i--){
            int pos = diff[i].second;
            if(aCount>0){
                if(costs[pos][1] <= costs[pos][0] && bCount > 0){
                    ans+=costs[pos][1];
                    bCount--;
                }
                else{
                    ans+=costs[pos][0];
                    aCount--;
                }
            }
            else{
                ans+=costs[pos][1];
                bCount--;
            }
        }
        return ans;
    }
};