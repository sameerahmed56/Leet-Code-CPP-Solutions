class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8, vector<int> (8, 0));
        vector<vector<int>> ans;
        for(int i=0;i<queens.size();i++){
            board[queens[i][0]][queens[i][1]] = 1;
        }
        for(int x=0; x<8;x++){
            int i= king[0], j=king[1];
            if(x==0){
                while(i >=0){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    i--;
                }
            }
            else if(x==1){
                while(i <= 7){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    i++;
                }
            }
            else if(x==2){
                while(j >=0 ){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    j--;
                }
            }
            else if(x==3){
                while(j <= 7){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    j++;
                }
            }
            else if(x==4){
                while(i <= 7 && j <= 7){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    i++;
                    j++;
                }
            }
            else if(x==5){
                while(i <= 7 && j >= 0){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    i++;
                    j--;
                }
            }
            else if(x==6){
                while(i >= 0 && j <= 7){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    i--;
                    j++;
                }
            }
            else if(x==7){
                while(i >= 0 && j >= 0){
                    if(board[i][j] == 1){
                        vector<int> curr;
                        curr.push_back(i);
                        curr.push_back(j);
                        ans.push_back(curr);
                        break;
                    }
                    i--;
                    j--;
                }
            }
        }
        return ans;
    }
};