class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int> &a, vector<int>&b){
            return a[1]<b[1];
        });
        int n=points.size(),ans=n ,end = points[0][1];
        for(int i=1; i<n;i++){
            if(end >= points[i][0]) ans--;
            else end = points[i][1];
        }
        return ans;
    }
};