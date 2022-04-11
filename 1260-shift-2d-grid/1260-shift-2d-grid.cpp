class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        queue<int> q;
        int m = grid.size(), n = m ? grid[0].size() : 0, count =0;
        k = k%(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int curr = (n*i)+j;
                curr+=k;
                int newI = (curr/n)%m, newJ =(curr%n);
                if(count<k){
                    q.push(grid[newI][newJ]);
                    grid[newI][newJ] = grid[i][j];
                }
                else{
                    q.push(grid[newI][newJ]);
                    grid[newI][newJ] = q.front();
                    q.pop();

                }
                count++;
            }
        }
        
        return grid;
    }
};