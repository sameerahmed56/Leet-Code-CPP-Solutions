class Solution {
public:
    void findMaxArea(vector<vector<int>>& grid, int i,int j,int m, int n, int& area){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        area++;
        findMaxArea(grid,i+1,j,m,n,area);
        findMaxArea(grid,i-1,j,m,n,area);
        findMaxArea(grid,i,j+1,m,n,area);
        findMaxArea(grid,i,j-1,m,n,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    findMaxArea(grid,i,j,m,n,area);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};