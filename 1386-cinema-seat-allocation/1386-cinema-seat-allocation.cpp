class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {  
        int m = seats.size(), ans = n<<1;
        bool leftBlock = false, midBlock = false, rightBlock = false;
        sort(seats.begin(),seats.end());
        int curr = -1;
        for(int i = 0; i < m; i++){
            if(seats[i][0] == curr){
                if(seats[i][1] >= 2 && seats[i][1] <= 5){
                    leftBlock = true;
                }
                if(seats[i][1] >= 4 && seats[i][1] <= 7){
                    midBlock = true;
                }
                if(seats[i][1] >= 6 && seats[i][1] <= 9){
                    rightBlock = true;
                }
            }
            else{
               curr = seats[i][0];
                if(leftBlock){
                    ans--;
                    if(rightBlock && midBlock){
                        ans--;
                    }
                }
                else if(rightBlock){
                    ans--;
                }
                
                i--;
                leftBlock = false;
                midBlock = false;
                rightBlock = false;
            }
        }
        if(leftBlock){
            ans--;
            if(rightBlock && midBlock){
                ans--;
            }
        }
        else if(rightBlock){
            ans--;
        }
        return ans;
    }
};