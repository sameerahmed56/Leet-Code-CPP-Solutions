class Solution {
public:
    bool search(vector<vector<int>>& mat, int target, int lRow, int rRow , int lCol, int rCol){
        if(lRow > rRow || lCol > rCol || mat[lRow][lCol] > target ||  target > mat[rRow][rCol] ) return false;
        int rowMid = lRow + ((rRow-lRow)/2);
        int colMid = lCol + ((rCol-lCol)/2);
        if(target == mat[rowMid][colMid]) return true;
        if(target > mat[rowMid][colMid]){
             return search(mat,target,rowMid + 1 ,rRow, lCol ,rCol) || search(mat,target, lRow, rowMid ,colMid+1 ,rCol);
        }
        return  search(mat,target, lRow, rowMid-1 ,  lCol,  rCol) || search(mat,target, rowMid, rRow , lCol,  colMid-1);
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n= mat[0].size(), lRow=0,rRow = m-1, lCol =0, rCol = n-1;
        return search(mat,target, lRow, rRow ,  lCol,  rCol);
    }
};