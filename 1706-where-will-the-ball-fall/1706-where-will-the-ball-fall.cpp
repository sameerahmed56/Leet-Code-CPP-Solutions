class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        for(int x = 0; x <n; x++){
            int i = 0, j = x; 
            while(i<m && j<n){
                if((grid[i][j] == 1 && j == n-1) || (grid[i][j] == 1 && grid[i][j+1] == -1)){
                    ans.push_back(-1);
                    break;
                }
                if((grid[i][j] == -1 && j == 0) || (grid[i][j] == -1 && grid[i][j-1] == 1)){
                    ans.push_back(-1);
                    break;
                }
                if(grid[i][j] == 1) j++;
                else if(grid[i][j] == -1) j--;
                i++;
            }
            if(i == m){
                ans.push_back(j);  
            }
        }
        return ans;
    }
};