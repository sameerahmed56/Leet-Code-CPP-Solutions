class Solution {
public:
    int minSwaps(string s) {
        int ans = 0, open = 0, close = 0;
        for(char c: s){
            if(c==']'){
                if(open<=close){
                    ans++;
                    open++;
                }
                else close++;
            }
            else open++; 
        }
        return ans;
    }
};