class Solution {
public:
    int fib(int n) {
        if(n<1) return n;
        int prev2 = 0, prev = 1;
        for(int i =2; i<=n; i++){
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};