class Solution {
public:
    void rottingOrange(vector<vector<int>>& grid,vector<vector<int>>& arr, int i,int j,int dist, bool isStart){
        int m = grid.size(), n = m ? grid[0].size() : 0;
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0 || (!isStart && grid[i][j]==2)){
            return;
        }
        grid[i][j] = 2;
        arr[i][j] = min(dist,arr[i][j]);
        dist++;
        rottingOrange(grid,arr,i+1,j,dist, false);
        rottingOrange(grid,arr,i-1,j,dist, false);
        rottingOrange(grid,arr,i,j+1,dist, false);
        rottingOrange(grid,arr,i,j-1,dist, false);
        isStart ? grid[i][j] = 2 : grid[i][j] = 1;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> arr(m , vector<int> (n, 100));
        for(int i = 0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    rottingOrange(grid,arr,i,j,0,true);
                }
            }
        }
        for(int i = 0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(arr[i][j]==100) return -1;
                    ans=max(ans,arr[i][j]);
                }
                
            }
        }
        return ans;
    }
};