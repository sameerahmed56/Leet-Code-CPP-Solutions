class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans( n , vector<int> (n, 1));
        int count = 1,i=0, j=0, edge = 0;
        while(count<=(n*n)){
            while(j<n-edge){
                ans[i][j]=count;
                j++;
                count++;
            }
            j--;
            i++;
            while(i<n-edge){
                ans[i][j]=count;
                i++;
                count++;
            }
            i--;
            j--;
            while(j>=0+edge){
                ans[i][j]=count;
                j--;
                count++;
            }
            j++;
            i--;
            while(i>=0+edge+1){
                ans[i][j]=count;
                i--;
                count++;
            }
            i++;
            j++;
            edge++;
        }
        return ans;
    }
};