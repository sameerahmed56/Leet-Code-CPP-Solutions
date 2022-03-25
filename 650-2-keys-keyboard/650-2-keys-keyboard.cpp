class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int i = 1, copied = i, ans = 0;
        while(i<n){
            if(n%(i+copied)==0){
                i = i+copied;
                copied = i;
                ans+=2;
            }
            else{
                i=i+copied;
                ans++;
            }
        }
        return ans;
    }
};