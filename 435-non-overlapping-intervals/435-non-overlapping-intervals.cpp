class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>&I) {
        sort(I.begin(),I.end());
        int n=I.size(), currStart =I[0][0],currEnd = I[0][1], ans=0;
        for(int i=1;i<n;i++){
            if(I[i][1] <= currEnd){
                currStart =I[i][0];
                currEnd = I[i][1];
                ans++;
            }
            else if(currEnd <= I[i][0]){
                currStart =I[i][0];
                currEnd = I[i][1];
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};