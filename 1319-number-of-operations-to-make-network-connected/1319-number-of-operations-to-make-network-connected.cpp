class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
		if(connections.size() < n-1) return -1; 
        vector<int> adj[n];
        for(int i = 0; i < connections.size(); ++i){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int isolated = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                isolated++;
                dfs(i,vis,adj);
            }
        }
        isolated--;
        return isolated;
    }
};