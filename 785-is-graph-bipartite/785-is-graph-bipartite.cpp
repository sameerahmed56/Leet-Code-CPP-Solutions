class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visi(n,false);
        unordered_set<int> first, second;
        bool isFirst = true;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!visi[i]){
                q.push(i);
                while(!q.empty()){
                    int size = q.size();
                    while(size>0){
                       int top = q.front();
                        q.pop();
                        visi[top] = true;
                        for(int j=0;j<graph[top].size();j++){
                            if(!visi[graph[top][j]]){
                                q.push(graph[top][j]);
                                visi[graph[top][j]] = true;
                            }
                            else{
                                if(isFirst){
                                    if(second.count(graph[top][j])) return false;
                                }
                                else{
                                    if(first.count(graph[top][j])) return false;
                                }
                            }
                            isFirst ? first.insert(graph[top][j]) : second.insert(graph[top][j]);
                        } 
                        size--;
                    }
                    isFirst = !isFirst;
                }
            }   
        }
        return true;
    }
};