class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<vector<int>> ans(grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int curr = (n*i)+j + k;
                int x = (curr/n)%m, y =(curr%n);
                ans[x][y] = grid[i][j];
            }
        }
        
        return ans;
    }
};