class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), sum = 0, nBythree = n/3;
        sort(piles.begin(),piles.end());
        for(int i =0; i<nBythree;i++){
            sum += piles[n-2];
            n=n-2;
        }
        return sum;
    }
};