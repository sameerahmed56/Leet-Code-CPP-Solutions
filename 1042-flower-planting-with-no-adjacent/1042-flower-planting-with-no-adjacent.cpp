class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n); 
        for(auto x: paths){
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            vector<bool> col (4,false);
            for(int j=0; j<adj[i].size(); j++){
                if(ans[adj[i][j]] != -1){
                    col[ans[adj[i][j]] - 1] = true;
                }
            }
            for(int k=0; k<4; k++){
                if(!col[k]){
                    ans[i] = k+1;
                    break;
                }
            }
        }
        return ans;
    }
};