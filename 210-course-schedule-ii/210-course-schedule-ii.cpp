class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        queue<int> q;
        vector<int> inorder(n,0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        for(auto a: pre){
            inorder[a[0]]++;
            adj[a[1]].push_back(a[0]);
        }
        for(int i=0;i<n;i++)
            if(inorder[i]==0)q.push(i);
        
        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto i: adj[curr]){
                if(--inorder[i]==0) q.push(i);
            }
        }
        return ans.size() == n ? ans : vector<int>() ;
    }
};