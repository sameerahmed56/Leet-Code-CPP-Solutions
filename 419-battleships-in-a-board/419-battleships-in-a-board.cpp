class Solution {
public:
    void remove(vector<vector<char>>& board, int i, int j, bool isDown){
        int m=board.size(), n=board[0].size();
        if(i<m && j<n){
            if(board[i][j] == 'X'){
                board[i][j] = '.';
                if(isDown){
                    remove(board,i+1,j,isDown);
                }
                else remove(board,i,j+1,isDown);
            }
        }
        return;
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size(), count =0; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X'){
                    count++;
                    remove(board,i,j+1,false);
                    remove(board,i+1,j,true);
                }
            }
        }
        return count;
    }
};