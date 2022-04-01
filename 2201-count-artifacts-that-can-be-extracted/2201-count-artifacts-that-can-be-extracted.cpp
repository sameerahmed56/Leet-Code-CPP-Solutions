class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
        int size = art.size();
        vector<vector<pair<int,int>>> vec( n , vector<pair<int,int>> (n,{-1,0}));
        vector<int> left(size,2);
        int ans = 0;
        for(int i=0; i<size;i++){
            int startRow = art[i][0],startCol = art[i][1], endRow = art[i][2], endCol = art[i][3], count = 0;
            for(int x=startRow; x<=endRow;x++){
                for(int y=startCol; y<=endCol;y++){
                    vec[x][y].second += 1;
                    vec[x][y].first = i;
                    count++;
                }
            }
            left[i] = count;
        }
        for(int i=0; i<dig.size();i++){
            if(vec[dig[i][0]][dig[i][1]].first >= 0){
                left[vec[dig[i][0]][dig[i][1]].first] -=  vec[dig[i][0]][dig[i][1]].second;
                if(left[vec[dig[i][0]][dig[i][1]].first] == 0) ans++; 
            }
        }
        return ans;
    }
};