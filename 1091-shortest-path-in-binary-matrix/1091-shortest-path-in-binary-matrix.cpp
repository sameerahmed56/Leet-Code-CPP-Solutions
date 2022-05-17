class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j, int n, vector<vector<bool>>& visi){
        
        return (i>=0 and i<n and j>=0 and j<n and grid[i][j]==0 and !visi[i][j]);   
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0, nodePushed ;
        vector<vector<bool>> visi( n,vector<bool> (n,0));
        queue<pair<int,int>> q;
        if(grid[0][0] == 0){
            q.push({0,0});
            visi[0][0] = true;
        }
        while(!q.empty()){
            nodePushed = q.size();
            ans++;
            for(int z = 0; z <nodePushed; z++){
                int row = q.front().first, col = q.front().second;
                visi[row][col] = true;
                q.pop();
                if(row == n-1 && col == n-1){
                    return ans;
                }
                int dRow[] = { -1, 0, 1, 0, 1, -1,-1, 1};
                int dCol[] = {  0, 1, 0,-1, 1, -1, 1,-1};
                for(int k=0;k<8;k++){
                    if(isValid(grid,row+dRow[k],col+dCol[k], n, visi)){
                        q.push({row+dRow[k],col+dCol[k]});
                        visi[row+dRow[k]][col+dCol[k]] = true;
                    }
                } 
            }
        }
        return -1;
    }
};