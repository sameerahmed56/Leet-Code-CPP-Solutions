class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
        return ; 
    }
    
    bool helper(vector<vector<char>>& board,int i,int j)
    {   if(i==9){return true;}
        if(j==9){ return helper(board,i+1,0);}
        if(board[i][j]!='.'){return helper(board,i,j+1);}
             
     for(int number=1;number<=9;number++)
        { if(can_place(board,i,j,'0'+ number))
            {  board[i][j]='0'+ number;
            
              bool can_solve=helper(board,i,j+1);
              if(can_solve==true){return true;}  
            }              
        }   
        board[i][j]='.';
        return false;
    }   
    
    bool can_place(vector<vector<char>>& board,int i,int j,char val)
    {
       int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) if(board[x][j] == val) return false;
    for(int y=0; y<9; y++) if(board[i][y] == val) return false;
    for(int x=0; x<3; x++)
    for(int y=0; y<3; y++)
        if(board[row+x][column+y] == val) return false;
    return true;
}
    
};