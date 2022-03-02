class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0; 
        uint32_t one = 1;
        for(int i = 0; i<32; i++){
            ans += n&one;
            n>>=1;
        }
        return ans;
    }
};