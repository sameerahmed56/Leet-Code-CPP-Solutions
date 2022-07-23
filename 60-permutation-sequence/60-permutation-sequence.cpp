class Solution {
public:
    int factorial(unsigned int n)
    {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }
    string getPermutation(int n, int k) {
        vector<int> used(n,0);
        string ans = "";
        k--;
        for(int i=0; i<n; i++){
            int fact = factorial(n-i);
            fact = fact/(n-i);
            int nThTerm = (k/fact); 
            k = k%fact;
            for(int j=0; j<n; j++){
                if(nThTerm == 0 && used[j] == 0){
                    ans += to_string(j+1);
                    used[j] = 1;
                    break;
                }
                if(used[j] == 0){
                    nThTerm--;
                }
            }
        }
        return ans;
        
    }
};