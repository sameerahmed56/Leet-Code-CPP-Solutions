class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int> &a, vector<int>&b){
            return a[1]<b[1];
        });
        int ans = 1, start = points[0][0], end = points[0][1], n=points.size();
        bool fired = false;
        for(int i=1; i<n;i++){
            ans++;
            if(end >= points[i][0]){
                ans--;
            }
            else{
                end = points[i][1];
                start = points[i][0];
                fired = false;
            }
        }
        return ans;
    }
};