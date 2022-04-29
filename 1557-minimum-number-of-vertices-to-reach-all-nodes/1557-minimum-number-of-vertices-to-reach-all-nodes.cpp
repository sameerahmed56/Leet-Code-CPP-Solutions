class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inorder(n,0), ans;
        vector<vector<int>> adj(n);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            inorder[x[1]]++;
        }
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};