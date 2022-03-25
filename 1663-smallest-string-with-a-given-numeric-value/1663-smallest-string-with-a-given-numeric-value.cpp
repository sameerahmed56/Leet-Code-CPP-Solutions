class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans =  string(n,'a');
        k-=n;
        for(int i=n-1; i >= 0; i--){
            int curr = min(k,25);
            ans[i] +=  curr;
            k-=curr;
        }
        return ans;
    }
};