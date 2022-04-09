class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> visi(n,false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!visi[i]){
                ans++;
                q.push(i);
                while(!q.empty()){
                    int x = q.front();
                    visi[x] = true;
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[x][j] == 1 && !visi[j]){
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};