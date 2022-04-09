class Solution {
public:
    void searchMatrix(vector<vector<char>>& grid, int i,int j,int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        searchMatrix(grid,i+1,j,m,n);
        searchMatrix(grid,i-1,j,m,n);
        searchMatrix(grid,i,j+1,m,n);
        searchMatrix(grid,i,j-1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' ){
                    searchMatrix(grid,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};