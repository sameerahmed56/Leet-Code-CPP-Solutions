class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<vector<int>> adjRev(n);
        vector<bool> visited(n,false);
        int ans = 0;
        queue<int>q;
        for(int i=0;i<n-1;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adjRev[connections[i][1]].push_back(connections[i][0]);
        }
        q.push(0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            visited[x]= true;
            for(int i=0;i<adj[x].size();i++){
                if(!visited[adj[x][i]]){
                    ans++;
                    q.push(adj[x][i]);
                }
            } 
            for(int i=0;i<adjRev[x].size();i++){
                if(!visited[adjRev[x][i]]){
                    q.push(adjRev[x][i]);
                }
            }
        }
        return ans;
    }
};