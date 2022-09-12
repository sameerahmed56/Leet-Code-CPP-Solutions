class Solution {
public:
    int bagOfTokensScore(vector<int>& tok, int power) {
        sort(tok.begin(),tok.end());
        int cnt = 0, l = 0, r =tok.size() -1;
        int ms=0;
        while(l<=r){
            if(tok[l] <= power){
                power -= tok[l++];
                cnt++;
            }
            else{
                if(cnt > 0){
                    power += tok[r--];
                    cnt--;
                }
                else break;
            }
            ms=max(ms,cnt);
        }
        return ms;
    }
};