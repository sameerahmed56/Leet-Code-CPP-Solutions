class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> freq;
        int m = mat.size(), n = mat[0].size();
        for(int i=0;i< m; i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                    break;
                count++;
            }
            freq.push_back({count,i});
        }
        sort(freq.begin(),freq.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};