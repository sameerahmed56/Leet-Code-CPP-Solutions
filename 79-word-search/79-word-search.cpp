class Solution {
public:
    bool search(vector<vector<char>>& board,vector<vector<bool>>& vis, string word, int i, int j, int k){
        if(k==word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || word[k] != board[i][j] || vis[i][j]) return false;
        int iTh[] = {-1,0,1,0};
        int jTh[] = {0,1,0,-1};
        vis[i][j] = true;
        for(int x=0; x<4; x++){
            if(search(board,vis, word, i+iTh[x], j+jTh[x], k+1)) return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), k = 0;
        vector<vector<bool>> vis(m, vector<bool> (n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[k] == board[i][j]){
                    if(search(board,vis, word, i, j, k)) return true;
                }
            }
        }
        return false;
    }
};