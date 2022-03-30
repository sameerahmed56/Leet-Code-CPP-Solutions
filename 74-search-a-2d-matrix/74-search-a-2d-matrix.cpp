class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0;
        while(i < m){
            if(target >= matrix[i][0] && target <= matrix[i][n-1]){
                int k = 0;
                while(k < n){
                    if(matrix[i][k] == target)
                    {
                        return true;
                    }
                    if(matrix[i][k] > target){
                        return false;
                    }
                    k++;
                }
            }
            i++;
        }
        return false;
    }
};