class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        queue<int> q;
        vector<int> inorder(n,0);
        vector<vector<int>> adj(n);
        int count =0;
        for(auto a: pre){
            inorder[a[0]]++;
            adj[a[1]].push_back(a[0]);
        }
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            count++;
            int curr = q.front();
            q.pop();
            for(auto i: adj[curr]){
                inorder[i]--;
                if(inorder[i]==0) q.push(i);
            }
        }
        return count == n;
    }
};