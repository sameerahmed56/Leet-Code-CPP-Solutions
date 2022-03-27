class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> freq;
        int m = mat.size(), n = mat[0].size();
        for(int i=0;i< m; i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                    break;
                count++;
            }
            freq.push({count,i});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq.top().second);
            freq.pop();
        }
        return ans;
    }
};