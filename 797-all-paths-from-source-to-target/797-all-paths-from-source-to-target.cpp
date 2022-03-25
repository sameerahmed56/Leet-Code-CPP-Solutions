class Solution {
public:
    vector<vector<int>> ans;
    void getPath(vector<vector<int>>& graph, int pos, int n, vector<int> arr){
        arr.push_back(pos);
        if(pos==n-1){
            ans.push_back(arr);
            return;
        }
        for(int i: graph[pos])
            getPath(graph,i,n, arr);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        getPath(graph,0,graph.size(), {});
        return ans;
    }
};