class Solution {
public:
    int numWays(string s) {
        long long mod = 1000000007;
        long long oneCount = 0, ans = 1, n = s.size();
        for(char c: s){
            if(c=='1') oneCount++;
        }
        if(oneCount%3 != 0) return 0;
        if(oneCount == 0){
            ans = ((n-1)*(n-2)/2)%mod;
        }
        else{
            oneCount /= 3;
            long long count = 0, midCount = 0;
            for(char c: s){
                if(c=='1'){
                    count++;
                    ans = ans * (midCount+1) % mod;
                    midCount = 0;
                }
                else if(count != 0 && count % oneCount == 0 && count < 3*oneCount){
                    midCount++;
                }
            }   
        }
        return (int)ans;
    }
};
